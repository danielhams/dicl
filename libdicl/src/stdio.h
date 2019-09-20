#ifndef LIBDICL_STDIO_H
#define LIBDICL_STDIO_H

#if defined(__GNUC__)
#include_next <stdio.h>
#undef printf
#define printf rpl_printf
#else
#include "/usr/include/stdio.h"
#undef printf
#define printf rpl_printf
#endif
int rpl_printf(const char *, ...);

#endif
