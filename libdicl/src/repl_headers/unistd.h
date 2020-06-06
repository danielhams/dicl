#ifndef LIBDICL_UNISTD_H
#define LIBDICL_UNISTD_H

#if defined(__GNUC__)
#include_next <unistd.h>
#else
#include "/usr/include/unistd.h"
#endif
#include "repl_select.h"

#if defined(__cplusplus)
extern "C" {
#endif

# define AT_FDCWD (-3041965)

# define AT_SYMLINK_NOFOLLOW 4096

# define AT_REMOVEDIR 1

# define AT_SYMLINK_FOLLOW 2

# define AT_EACCESS 4

int faccessat(int, const char*, int, int);

int readlinkat(int fd, const char *path, char *buf, size_t bufsize);

#if defined(__cplusplus)
}
#endif

#endif
