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
extern ssize_t rpl_getline(char **lineptr, size_t *n, FILE *stream);
#endif

extern ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);

extern int dprintf(int __fd, const char * __fmt, ...)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 3)))
#endif
;

  extern int vdprintf(int __fd, const char* __fmt, va_list)
#if defined(__GNUC__)
  __attribute__ ((format (__printf__, 2, 0)))
#endif
;

  /*
   * The funopen implementation is just enough to
   * get libsolv working (and maybe a bit more) - and requires
   * linking in of the library dedicated to it (libdiclfunopen)
   * so these replacements are guarded by a macro.
   * Don't expect this stuff to "just work" for you! It probably
   * won't.
   */
#if defined(LIBDICL_NEED_FUNOPEN)

#define funopen ld_funopen
extern FILE * ld_funopen( const void * cookie,
       int (*readfn)(void *cookie, char *buf, int nmem),
       int (*writefn)(void *cookie, const char *buf, int nmem),
       off_t (*seekfn)(void *cookie, off_t offset, int whence),
       int (*closefn)(void *cookie) );

#undef fopen
#define fopen ld_fopen
extern FILE * ld_fopen( const char *path, const char *mode );
#undef fclose
#define fclose ld_fclose
extern int ld_fclose( FILE *stream );

#undef fread
#define fread ld_fread
extern size_t ld_fread( void *ptr, size_t size, size_t nmemb, FILE *stream );

#undef fwrite
#define fwrite ld_fwrite
extern size_t ld_fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream );

#undef fseek
#define fseek ld_fseek
extern size_t ld_fseek( FILE *stream, long offset, int whence );

#undef feof
#define feof ld_feof
extern int ld_feof( FILE *stream );

#undef ferror
#define ferror ld_ferror
extern int ld_ferror( FILE *stream );

#undef fgets
#define fgets ld_fgets
extern char *ld_fgets( char *s, int size, FILE *stream );

#undef fgetc
#define fgetc ld_fgetc
extern int ld_fgetc( FILE *stream );

#undef ungetc
#define ungetc ld_ungetc
extern int ld_ungetc( int c, FILE *stream );

#endif

#if defined(__cplusplus)
}
#endif

#endif
