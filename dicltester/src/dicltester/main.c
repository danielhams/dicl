#include "config.h"

#if defined(USE_LIBDICL)
#include <libdicl/libdicl.h>
#endif

#include <stdio.h>

#include "dicl_printf.h"
#include "dicl_fprintf.h"
#include "dicl_vsnprintf.h"
#include "dicl_select.h"
#include "dicl_setenv.h"
#include "dicl_strtod.h"
#include "dicl_strtoll.h"

int main(int argc, char**argv)
{
    printf("Dicltester called.\n");

#if defined(USE_LIBDICL)
    printf("libdicl version is -> %s\n",
	   libdicl_getversion());
#else
    printf("compiled _without_ libdicl replacements!\n");
#endif

    dicl_printftest();

    dicl_fprintftest();

    dicl_vsnprintftest();

    dicl_selecttest();

    dicl_setenvtest(argv);

    dicl_strtodtest();

    dicl_strtolltest();

    return 0;
}
