#ifndef LIBDICL_STDIO_H
#define LIBDICL_STDIO_H

#if defined(__GNUC__)
#include_next <stdio.h>
#else
#include "/usr/include/stdio.h"
#endif

extern int asprintf(char **,const char *, ...);

#undef sprintf
#define sprintf rpl_sprintf
extern int rpl_sprintf(char *,const char *, ...);

#undef printf
#define printf rpl_printf
extern int rpl_printf(const char *, ...);

#undef fprintf
#define fprintf rpl_fprintf
extern int rpl_fprintf(FILE *, const char *, ...);

#undef vfprintf
#define vfprintf rpl_vfprintf
extern int rpl_vfprintf(FILE *, const char *, va_list);

#undef vsprintf
#define vsprintf rpl_vsprintf
extern int rpl_vsprintf(char *,const char *, va_list);

#undef vsnprintf
#define vsnprintf rpl_vsnprintf
extern int rpl_vsnprintf(char *,size_t,const char *, va_list);

extern int vasprintf(char**, const char*, va_list);

/* Missing pieces */
#undef getline
#define getline rpl_getline
ssize_t rpl_getline(char **lineptr, size_t *n, FILE *stream);
#undef getdelim
#define getdelim rpl_getdelim
ssize_t rpl_getdelim(char **lineptr, size_t *n, int delim, FILE *stream);

#endif
