#ifndef LIBDICL_DIRENT_H
#define LIBDICL_DIRENT_H

#if defined(__GNUC__)
#include_next <dirent.h>
#else
#include "/usr/include/dirent.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/* Extra things not in Irix libc */
extern DIR *fdopendir(int fd);

#if defined(__cplusplus)
}
#endif

#endif
