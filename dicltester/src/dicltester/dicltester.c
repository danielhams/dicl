#include <libdicl/libdicl.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
    printf("Dicltester called.\n");

    printf("libdicl version is -> %s\n",
           libdicl_getversion());

    size_t somesize = 0;

    printf("printf is %s\n", "printf");

    printf("The size with %%ld is %ld\n", somesize);
    printf("The size with %%zd is %zd\n", somesize);

    return 0;
}
