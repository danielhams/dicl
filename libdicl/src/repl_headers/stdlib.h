#ifndef LIBDICL_STDLIB_H
#define LIBDICL_STDLIB_H

#if defined(__GNUC__)
#include_next <stdlib.h>
#else
#include "/usr/include/stdlib.h"
#endif
#undef strtod
#define strtod rpl_strtod
extern double rpl_strtod(const char *, char **);
#undef strtold
#define strtold rpl_strtold
extern long double rpl_strtold(const char *, char **);

#endif
