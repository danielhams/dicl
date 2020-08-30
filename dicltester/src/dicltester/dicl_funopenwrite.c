#include "config.h"

#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include <errno.h>

#include <dicl_funopencommon.h>

void dicl_funopenwritetest( char **argv )
{
  void * thecookie = (void*)26;

  if( errno ) {
    printf("Oops - errno set before call - it is %d\n", errno);
    exit(2);
  }

  FILE * the_stream_ptr = funopen( thecookie,
				   NULL,
				   mywritefn,
				   NULL,
				   myclosefn );

  if( errno ) {
    printf("Oops - errno is %d\n", errno);
    exit(2);
  }

  char result[2048];
  int offset=0;
  int num_needed = 32;
  for( int i = 0 ; i < num_needed ; ++i ) {
    result[i] = 'b';
  }

  while( offset < num_needed ) {
    int num_this_round = 16;
    int num_actually_written = fwrite( result+offset, 1, num_this_round, the_stream_ptr);
    if( num_actually_written == 0 ) {
      printf("Nothing returned errno=%d\n", errno);
      exit (4);
    }
    printf("Write OK\n");
    offset+=num_this_round;
  }
  fflush(the_stream_ptr);
  //fclose(the_stream_ptr);
  if( errno ) {
    printf("FOWT (end) errno is set %d\n", errno);
  }

  return;
}
