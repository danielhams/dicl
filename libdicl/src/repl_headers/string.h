#ifndef LIBDICL_STRING_H
#define LIBDICL_STRING_H

#if defined(__GNUC__)
#include_next <string.h>
#else
#include "/usr/include/string.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/* Replacements */
#undef strstr
#define strstr rpl_strstr
extern char *strstr(const char*, const char*);

/* Missing pieces */
extern void *mempcpy(void *, const void* ,size_t);

extern void *memmem( const void *haystack, size_t haystack_size,
		     const void *needle, size_t needlelen);

extern void *memrchr( const void *s, int c, size_t n);

extern void *rawmemchr( const void *s, int c);

extern char *stpcpy(char *, const char*);
extern char *stpncpy(char *, const char*, size_t);

extern char * strchrnul(const char *, int);

extern int strerror_r(int, char*, size_t);

extern char *strndup(const char*, size_t);

extern char *strsep(char **, char*);

extern char *strcasestr(const char*, const char*);

extern char *strsignal(int sig);
/* If you are looking for an associated sys_siglist - try _sys_siglist */

extern size_t strnlen(const char*, size_t);

#if defined(__cplusplus)
}
#endif

#endif
