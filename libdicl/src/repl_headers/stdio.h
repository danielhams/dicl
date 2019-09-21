#ifndef LIBDICL_STDIO_H
#define LIBDICL_STDIO_H

#if defined(__GNUC__)
#include_next <stdio.h>
#else
#include "/usr/include/stdio.h"
#endif
#undef printf
#define printf rpl_printf
extern int rpl_sprintf(char *,const char *, ...);
extern int rpl_printf(const char *, ...);
extern int rpl_vfprintf(FILE *, const char *, va_list);
extern int rpl_vsprintf(char *,const char *, va_list);

#endif
