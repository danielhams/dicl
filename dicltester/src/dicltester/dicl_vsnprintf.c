#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <errno.h>

#define TEST_LENGTH 64

int actual_tester( char * output_buf, const char * fmt, ...)
{
  va_list ap;
  int n;
  va_start(ap, fmt);
  n = vsnprintf( output_buf, TEST_LENGTH, fmt, ap );
  va_end(ap);
  return n;
}

void dicl_vsnprintftest()
{
  printf("Beginning vsnprintf test\n");

  char output_buf[TEST_LENGTH];
  output_buf[0] = '\0';

  int num_printed = actual_tester( output_buf, "Test1 %d", 5 );

  printf("Num printed=%d\n", num_printed);
  printf("Result in output_buf=%s\n", output_buf);

  // Posix printf doesn't support "%m" - that's a gnu extension....
  // O great.
  num_printed = actual_tester( output_buf, "Blah of %%blah to %s: %m\n",
			       "somestring");

  printf("Num printed=%d\n", num_printed);
  if( num_printed > 0 ) {
    printf("Result in output_buf=%s\n", output_buf);
  }
  else {
    printf("No output with %%m\n");
  }

  return;
}
