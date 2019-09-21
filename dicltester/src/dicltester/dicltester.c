#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <libdicl/libdicl.h>

#include "dicl_select.h"

int main(int argc, char**argv)
{
    printf("Dicltester called.\n");

    printf("libdicl version is -> %s\n",
           libdicl_getversion());

    size_t somesize = 0;

    printf("printf is %s\n", "printf");

    printf("The size_t with %%ld is %ld\n", somesize);
    printf("The size_t with %%zd is %zd\n", somesize);

    ptrdiff_t ptrd = 0;

    printf("The ptrdiff_t with %%ld is %ld\n", ptrd);
    printf("The ptrdiff_t with %%td is %td\n", ptrd);

    dicl_selecttest();

    return 0;
}
