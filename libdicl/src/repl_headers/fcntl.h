#ifndef LIBDICL_FCNTL_H
#define LIBDICL_FCNTL_H

#if defined(__GNUC__)
#include_next <fcntl.h>
#else
#include "/usr/include/fcntl.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

  /* Missing pieces */
  extern int openat(int fd, const char *path, int oflag, ...);

#if defined(__cplusplus)
}
#endif

#endif
