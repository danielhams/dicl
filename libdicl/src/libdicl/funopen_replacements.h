/*
 * funopen_replacements.h
 *
 *  Created on: 12 Aug 2020
 *      Author: danielhams on github
 */

#ifndef LIBDICL_FUNOPEN_REPLACEMENTS_HPP_
#define LIBDICL_FUNOPEN_REPLACEMENTS_HPP_

#include <stdio.h>

#if defined(__cplusplus)
extern "C" {
#endif

extern FILE * ld_funopen( const void * cookie,
            int (*readfn)(void *cookie, char *buf, int nmem),
            int (*writefn)(void *cookie, const char *buf, int nmem),
            off_t (*seekfn)(void *cookie, off_t offset, int whence),
            int (*closefn)(void *cookie));

extern FILE * ld_fopen( const char *path, const char *mode);
extern int ld_fclose( FILE *stream);

extern size_t ld_fread( void *ptr, size_t size, size_t nmemb, FILE *stream);

extern size_t ld_fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream);

extern size_t ld_fseek( FILE *stream, long offset, int whence );

extern int ld_feof( FILE * stream );

extern int ld_ferror( FILE * stream );

extern char *ld_fgets( char *s, int size, FILE *stream );

extern int ld_fgetc( FILE *stream );

extern int ld_ungetc( int c, FILE *stream );

#if defined(__cplusplus)
}
#endif

#endif /* LIBDICL_FUNOPEN_REPLACEMENTS_HPP_ */
