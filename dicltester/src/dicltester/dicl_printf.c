#include <stdio.h>
#include <stddef.h>

void dicl_printftest()
{
  printf("Beginning printf test\n");
  size_t somesize = 0;

  printf("The size_t with %%ld is %ld\n", somesize);
  printf("The size_t with %%zd is %zd\n", somesize);

  ptrdiff_t ptrd = 0;

  printf("The ptrdiff_t with %%ld is %ld\n", ptrd);
  printf("The ptrdiff_t with %%td is %td\n", ptrd);

  return;
}
