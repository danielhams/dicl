#ifndef LIBDICL_STDIO_H
#define LIBDICL_STDIO_H

#if defined(__GNUC__)
#include_next <stdio.h>
#else
#include "/usr/include/stdio.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

extern int asprintf(char **,const char *, ...)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 3)))
#endif
;

#undef sprintf
#define sprintf rpl_sprintf
extern int rpl_sprintf(char *,const char *, ...)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 3)))
#endif
;

#undef printf
#define printf rpl_printf
extern int rpl_printf(const char *, ...)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 1, 2)))
#endif
;

#undef fprintf
#define fprintf rpl_fprintf
extern int rpl_fprintf(FILE *, const char *, ...)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 3)))
#endif
;

#undef vfprintf
#define vfprintf rpl_vfprintf
extern int rpl_vfprintf(FILE *, const char *, va_list)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 0)))
#endif
;

#undef vsprintf
#define vsprintf rpl_vsprintf
extern int rpl_vsprintf(char *,const char *, va_list)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 0)))
#endif
;

#undef vsnprintf
#define vsnprintf rpl_vsnprintf
extern int rpl_vsnprintf(char *,size_t,const char *, va_list)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 3, 0)))
#endif
;

extern int vasprintf(char**, const char*, va_list)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 0)))
#endif
;

/* Missing pieces */

/* getline is a little special, in that redefining it here like
 * this can cause C++ std::basicstream::getline to become difficult
 * to link with. For that reason, if we are C++, you must specify
 * LIBDICL_WANTS_CPP_GETLINE_REPL
 */
#if !defined(__cplusplus) || defined(LIBDICL_WANTS_CPP_GETLINE_REPL)
#undef getline
#define getline rpl_getline
ssize_t rpl_getline(char **lineptr, size_t *n, FILE *stream);
#endif

ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);

#if defined(__cplusplus)
}
#endif

#endif
