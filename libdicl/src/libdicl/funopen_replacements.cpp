/*
 * funopen_replacements.cpp
 *
 * An implementation of BSD "funopen" intended to work
 * by intercepting stream calls and either using the cookie
 * style functions for things that were "funopened" or using
 * the regular libc path for non-cookie streams.
 *
 * There is _just enough_ functionality here to support the libsolv
 * library, and it's probably missing quite a few stream calls.
 *
 *  Created on: 12 Aug 2020
 *      Author: danielhams on github
 */

#include "funopen_replacements.h"

#include <unistd.h>
#include <fcntl.h>

#include <string>
#include <unordered_map>
#include <mutex>
#include <functional>
#include <algorithm>
#include <iterator>
#include <atomic>
#include <optional>
#include <iostream>
#include <thread>

using std::unordered_map;
using std::mutex;
using std::unique_lock;
using std::atomic;
using std::optional;
using std::cout;
using std::cerr;
using std::endl;
using std::thread;

static constexpr int FO_DEBUG = 0;

struct cookie_functions
{
  void * cookie;
  int (*readfn)(void *cookie, char *buf, int nmem);
  int (*writefn)(void *cookie, const char *buf, int nmem);
  off_t (*seekfn)(void *cookie, off_t offset, int whence);
  int (*closefn)(void *cookie);
};

struct internal_funopen_data
{
  cookie_functions cookie_funcs;
  FILE * real_stream_ptr;
  int fds[2];
  bool is_read;
  int fd;
};

static void fail( const char * where )
{
  std::cerr << "Failure in funopen: " << where << std::endl;
  exit(-1);
}

static void funopen_thread_func( internal_funopen_data funopen_data ) {
  bool is_read = funopen_data.is_read;
  cookie_functions & cookie_funcs = funopen_data.cookie_funcs;
  void * cookie = cookie_funcs.cookie;
  char local_buf[1024];
  //  cout << "CT in mode is_read_mode=" << is_read << endl;

  while(true) {
    int num_this_time = sizeof(local_buf);
    //    cout << "CTR Attempting to read " << num_this_time << endl;
    int num_read = is_read ?
      cookie_funcs.readfn(cookie, local_buf, num_this_time)
      :
      read(funopen_data.fd, local_buf, num_this_time);
    //    cout << "CTR Actually read " << num_read << endl;
    if( num_read < 0 ) {
      if (errno != EINTR) { break; }
      continue;
    }
    if( num_read == 0 ) {
      break;
    }
    int num_left = num_read;
    int num_written = 0;
    while( num_left > 0 ) {
      //      cout << "CTW ls num_left " << num_left << endl;
      int num_written_now = is_read ?
	write(funopen_data.fd, local_buf + num_written, num_left)
	:
	cookie_funcs.writefn(cookie, local_buf + num_written, num_left);
      //      cout << "CTW num_written_now " << num_written_now << endl;
      if( num_written_now < 0 ) {
	if( errno != EINTR ) { break; }
	continue;
      }
      if( num_written_now == 0 ) { break; }

      num_left -= num_written_now;
      num_written += num_written_now;
    }
    //    cout << "CTW loop check num_left " << num_left << endl;
    if( num_left > 0 ) { break; }
  }
  //  cout << "CTW loop done " << endl;

  if( cookie_funcs.closefn ) { cookie_funcs.closefn( cookie ); }
  close(funopen_data.fd);

  //  cout << "CT finish errno=" << errno << endl;

  return;
}

static const char *fo_read_mode = "r";
static const char *fo_write_mode = "w";

FILE * ld_funopen( const void * cookie,
        int (*readfn)(void *cookie, char *buf, int nmem),
        int (*writefn)(void *cookie, const char *buf, int nmem),
        off_t (*seekfn)(void *cookie, off_t offset, int whence),
        int (*closefn)(void *cookie))
{
  if( seekfn ) {
    errno = ENOTSUP;
    if (FO_DEBUG) {
      cerr << "FO seek passed" << endl;
    }
    return NULL;
  }
  const char * mode;
  int rd=0;
  int wr=0;
  if( readfn && writefn ) {
    errno = ENOTSUP;
    if (FO_DEBUG) {
      cerr << "FO read + write passed" << endl;
    }
    return NULL;
  }
  else if( readfn ) {
    mode = fo_read_mode;
    rd=1;
  }
  else {
    mode = fo_write_mode;
    wr=1;
  }
  cookie_functions funcs {
      .cookie = (void*)cookie,
      .readfn  = readfn,
      .writefn = writefn,
      .seekfn  = seekfn,
      .closefn = closefn
  };
  internal_funopen_data funopen_data {
      .cookie_funcs = funcs,
      .real_stream_ptr = NULL,
      .fds = {0, 0},
      .is_read = (readfn != NULL),
      .fd = 0
  };
  int pipe_rv = pipe(&funopen_data.fds[0]);
  if( pipe_rv ) {
    if (FO_DEBUG) {
      cerr << "FO pipe fail" << endl;
    }
    return NULL;
  }
  int fd0coe_rv = fcntl(funopen_data.fds[0], FD_CLOEXEC);
  if( fd0coe_rv ) {
    if (FO_DEBUG) {
      cerr << "FO failed 0 fcntl" << endl;
    }
    if( close(funopen_data.fds[0]) ) {
      cerr << "failed cloexec and close of 0" << endl;
    }
    if( close(funopen_data.fds[1]) ) {
      cerr << "failed cloexec and close of 1" << endl;
    }
    return NULL;
  }
  int fd1coe_rv = fcntl(funopen_data.fds[1], FD_CLOEXEC);
  if( fd1coe_rv ) {
    if (FO_DEBUG) {
      cerr << "FO failed 1 fcntl" << endl;
    }
    if( close(funopen_data.fds[0]) ) {
      cerr << "failed cloexec and close of 0" << endl;
    }
    if( close(funopen_data.fds[1]) ) {
      cerr << "failed cloexec and close of 1" << endl;
    }
    return NULL;
  }

  funopen_data.real_stream_ptr = fdopen(funopen_data.fds[wr], mode);
  if( funopen_data.real_stream_ptr == NULL ) {
    if (FO_DEBUG) {
      cerr << "FO failed fdopen" << endl;
    }
    if( close(funopen_data.fds[0]) ) {
      cerr << "failed fdopen and close of 0" << endl;
    }
    if( close(funopen_data.fds[1]) ) {
      cerr << "failed fdopen and close of 1" << endl;
    }
    return NULL;
  }
  funopen_data.fd = funopen_data.fds[rd];
  thread proxy_thread( funopen_thread_func, funopen_data );
  proxy_thread.detach();

  return funopen_data.real_stream_ptr;
}
