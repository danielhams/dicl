#ifndef LIBDICL_STRING_H
#define LIBDICL_STRING_H

#if defined(__GNUC__)
#include_next <string.h>
#else
#include "/usr/include/string.h"
#endif

/* Missing pieces */
char * strchrnul(const char *, int);

#endif
