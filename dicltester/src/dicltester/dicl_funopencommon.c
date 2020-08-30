#include "config.h"

#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include <errno.h>

int myreadfn( void * cookie, char * buf, int nmem ) {
  static int num_read_total=0;
  if( num_read_total > 4096 ) {
    printf("myreadfn hit limit\n");
    return 0;
  }
  int cookieasint = (int)cookie;
  printf("myreadfn with cookie(%d) asked for %d\n", cookieasint, nmem);
  for( int i = 0; i < nmem ; ++i ) {
    buf[i] = 'c';
  }
  num_read_total += nmem;
  return nmem;
}

int mywritefn( void * cookie, char * buf, int nmem ) {
  int cookieasint = (int)cookie;
  printf("mywritefn with cookie(%d) asked for %d\n", cookieasint, nmem);
  for( int i = 0; i < nmem ; ++i ) {
    printf("%c\n", buf[i]);
  }
  return nmem;
}

int myclosefn( void * cookie ) {
  int cookieasint = (int)cookie;
  printf("myclosefn with cookie(%d)\n", cookieasint);
  return 0;
}
