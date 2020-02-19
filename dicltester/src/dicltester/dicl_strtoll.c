#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void dicl_strtolltest()
{
  printf("Beginning strtoll test\n");
  errno=0;

  const char * testuintmax = "2147483647";
  char * oobll = "1234567890123456789012345678901234567890";
  int vi = atoi(testuintmax);

  printf("With atoi errno=%d value=%d\n",errno,vi);

  long long vll1 = strtoll(testuintmax,NULL,10);
  printf("With strtoll errno=%d value=%li\n",errno,vll1);
  int errnobefore = errno;

  char * oobll_end;
  long vll2 = strtol(oobll,&oobll_end,10);
  printf("With strtol errno=%d value=%ld\n",errno,vll2);
  errno=0;

  long long vll3 = strtoll(testuintmax,NULL,10);
  printf("With strtoll errno=%d value=%li\n",errno,vll3);
  int errnoafter = errno;

  if( errnobefore != 0 || errnoafter != 0 || (errnobefore != errnoafter)) {
    printf("Something strange is happening with strtoll!\n");
  }

  return;
}
