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

#if defined(__cplusplus)
}
#endif

#endif /* LIBDICL_FUNOPEN_REPLACEMENTS_HPP_ */
