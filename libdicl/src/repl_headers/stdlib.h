#ifndef LIBDICL_STDLIB_H
#define LIBDICL_STDLIB_H

#if defined(__GNUC__)
#include_next <stdlib.h>
#else
#include "/usr/include/stdlib.h"
#endif
#undef strtod
#define strtod rpl_strtod
extern double strtod(const char *, char **);

#endif
