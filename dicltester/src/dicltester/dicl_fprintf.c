#include <stdio.h>
#include <stddef.h>

void dicl_fprintftest()
{
  printf("Beginning fprintf test\n");

  size_t somesize = 0;

  fprintf(stdout, "The size_t with %%d is %d\n", somesize);
  fprintf(stdout, "The size_t with %%zd is %zd\n", somesize);

  ptrdiff_t ptrd = 0;

  fprintf(stdout, "The ptrdiff_t with %%d is %d\n", ptrd);
  fprintf(stdout, "The ptrdiff_t with %%td is %td\n", ptrd);

  return;
}
