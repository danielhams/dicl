#ifndef LIBDICL_SYS_STAT_H
#define LIBDICL_SYS_STAT_H

#if defined(__GNUC__)
#include_next <sys/stat.h>
#else
#include "/usr/include/sys/stat.h"
#endif

int fstatat(int fd, const char *path, struct stat *buf, int flag);

#endif
