#include "funopen_replacements.h"

#include <string>
#include <unordered_map>
#include <mutex>
#include <functional>
#include <algorithm>
#include <iterator>
#include <atomic>
#include <optional>

using std::unordered_map;
using std::mutex;
using std::unique_lock;
using std::atomic;
using std::optional;

struct cookie_functions
{
  void * cookie;
  int (*readfn)(void *cookie, char *buf, int nmem);
  int (*writefn)(void *cookie, const char *buf, int nmem);
  off_t (*seekfn)(void *cookie, off_t offset, int whence);
  int (*closefn)(void *cookie);
};

struct internal_file_ptr_entry
{
    bool is_cookie_stream;
    union
    {
        FILE * real_stream_ptr;
        cookie_functions cookie_funcs;
    };
};

static mutex internal_cookie_mutex;
// Must start from zero (otherwise it's a "NULL" pointer)
// Also, this is assuming that "wrapping" is ok, which it maybe isn't
static atomic<size_t> key_counter { 1 };
static unordered_map<size_t, internal_file_ptr_entry> internal_cookie_map;

static size_t get_next_key() noexcept
{
    size_t next_key = key_counter++;
    return next_key;
}

static void insert_entry( size_t key, internal_file_ptr_entry value )
{
    unique_lock<mutex> lock( internal_cookie_mutex );
    internal_cookie_map.emplace( key, value);
}

static FILE * key_to_stream( size_t key )
{
    return (FILE *)(key);
}

static optional<internal_file_ptr_entry> find_entry_for_key( size_t key )
{
    unique_lock<mutex> lock( internal_cookie_mutex );
    auto finder = internal_cookie_map.find( key );
    if( finder != internal_cookie_map.end() )
    {
        return { finder->second };
    }
    else
    {
        return {};
    }
}

static optional<internal_file_ptr_entry> find_remove_entry_for_key( size_t key )
{
    unique_lock<mutex> lock( internal_cookie_mutex );
    auto finder = internal_cookie_map.find( key );
    if( finder != internal_cookie_map.end() )
    {
        internal_cookie_map.erase(finder);
        return { finder->second };
    }
    else
    {
        return {};
    }
}

static size_t stream_to_key( FILE * stream )
{
    return (size_t)(stream);
}

FILE * ld_funopen( const void * cookie,
        int (*readfn)(void *cookie, char *buf, int nmem),
        int (*writefn)(void *cookie, const char *buf, int nmem),
        off_t (*seekfn)(void *cookie, off_t offset, int whence),
        int (*closefn)(void *cookie))
{
    size_t next_key = get_next_key();
    cookie_functions funcs {
        .cookie = (void*)cookie,
        .readfn  = readfn,
        .writefn = writefn,
        .seekfn  = seekfn,
        .closefn = closefn,
    };
    internal_file_ptr_entry entry {
        .is_cookie_stream = false,
        .cookie_funcs = funcs
    };
    insert_entry( next_key, entry );
    return key_to_stream( next_key );
}

FILE * ld_fopen( const char *path, const char *mode )
{
    FILE * actual_stream = fopen( path, mode );
    size_t next_key = get_next_key();
    internal_file_ptr_entry entry {
        .is_cookie_stream = true,
        .real_stream_ptr = actual_stream
    };
    insert_entry( next_key, entry );
    return key_to_stream( next_key );
}

int ld_fclose( FILE *stream )
{
    size_t key = stream_to_key(stream);
    optional<internal_file_ptr_entry> entry_opt = find_remove_entry_for_key(key);
    if( !entry_opt )
    {
        exit(-1);
    }
    internal_file_ptr_entry entry = *entry_opt;
    if( !entry.is_cookie_stream )
    {
        return fclose( entry.real_stream_ptr );
    }
    else
    {
        // Call funopen close function
      return entry.cookie_funcs.closefn( entry.cookie_funcs.cookie);
    }
}

size_t ld_fread( void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t key = stream_to_key(stream);
    optional<internal_file_ptr_entry> entry_opt = find_entry_for_key(key);
    if( !entry_opt )
    {
        exit(-1);
    }
    internal_file_ptr_entry entry = *entry_opt;
    if( !entry.is_cookie_stream )
    {
        return fread( ptr, size, nmemb, entry.real_stream_ptr );
    }
    else
    {
      return entry.cookie_funcs.readfn( entry.cookie_funcs.cookie,
					(char*)ptr, (nmemb*size) );
    }
}

size_t ld_fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t key = stream_to_key(stream);
    optional<internal_file_ptr_entry> entry_opt = find_entry_for_key(key);
    if( !entry_opt )
    {
        exit(-1);
    }
    internal_file_ptr_entry entry = *entry_opt;
    if( !entry.is_cookie_stream )
    {
        return fwrite( ptr, size, nmemb, entry.real_stream_ptr );
    }
    else
    {
      return entry.cookie_funcs.writefn( entry.cookie_funcs.cookie,
					 (char*)ptr, (nmemb*size) );
    }
}

size_t ld_fseek( FILE *stream, long offset, int whence )
{
    size_t key = stream_to_key(stream);
    optional<internal_file_ptr_entry> entry_opt = find_entry_for_key(key);
    if( !entry_opt )
    {
        exit(-1);
    }
    internal_file_ptr_entry entry = *entry_opt;
    if( !entry.is_cookie_stream )
    {
        return fseek( entry.real_stream_ptr, offset, whence );
    }
    else
    {
      return entry.cookie_funcs.seekfn( entry.cookie_funcs.cookie,
					offset, whence );
    }
}
