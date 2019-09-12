#include <libdicl/libdicl.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
    printf("Dicltester called.\n");

    printf("libdicl version is -> %s\n",
           libdicl_getversion());

    return 0;
}
