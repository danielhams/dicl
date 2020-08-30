#include "config.h"

#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include <errno.h>

#include <dicl_funopencommon.h>

void dicl_funopenreadtest( char **argv )
{
  printf("Beginning funopen read test\n");

  void * thecookie = (void*)26;

  FILE * the_stream_ptr = funopen( thecookie,
				   myreadfn,
				   NULL,
				   NULL,
				   myclosefn );

  if( errno ) {
    printf("Oops\n");
    exit(2);
  }

  char result[2048];
  int offset=0;
  int num_needed = 20;

  while( offset < num_needed ) {
    if( errno ) {
      printf("FORT (loopstart) errno is set %d\n", errno);
    }
    int num_this_round = 16;
    int num_actually_read = fread( result+offset, 1, num_this_round, the_stream_ptr);
    if( num_actually_read == 0 ) {
      printf("Nothing returned errno=%d\n", errno);
      exit (4);
    }
    printf("Read OK - have:\n");
    for( int i = 0 ; i < num_this_round; ++i ) {
      printf("%c\n", *((char*)result+offset+i));
    }
    offset+=num_this_round;
    if( errno ) {
      printf("FORT (loopend) errno is set %d\n", errno);
    }
  }
  if( errno ) {
    printf("FORT (end-1) errno is set %d\n", errno);
  }
  //printf("Calling fclose\n");
  //  fclose(the_stream_ptr);
  //printf("Called fclose\n");
  if( errno ) {
    printf("FORT (end) errno is set %d\n", errno);
  }

  return;
}
