#include "config.h"

#include <stdlib.h>

#include <stdio.h>
#include <string.h>

void dumpenv( char *mapname, char **valarray )
{
  char **curp = valarray;
  char *valp = *curp;
  curp++;
  while( valp != NULL )
    {
      printf("%s.arg=%s\n", mapname, valp);
      valp = *curp;
      curp++;
    }
}

void dicl_setenvtest( char **argv )
{
  printf("Beginning setenv test\n");

#if defined(USE_LIBDICL)
  // Some investigation code
  //  extern char **environ;
  //  dumpenv("argv",argv);
  //  dumpenv("enva",environ);

  setenv("TEST_DICL_ENVVAR","bananas",0);
  char *bananas;
  bananas = getenv("TEST_DICL_ENVVAR");
  printf("Do we have fruit->%s\n", bananas);
  unsetenv("TEST_DICL_ENVVAR");
  bananas = getenv("TEST_DICL_ENVVAR");
  printf("Should no longer have fruit->%s\n", bananas);
#else
  printf("setenv tests not possible - irix has no setenv!\n");
#endif

  return;
}
