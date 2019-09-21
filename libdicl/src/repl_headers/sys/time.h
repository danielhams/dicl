#ifndef LIBDICL_SYS_TIME_H
#define LIBDICL_SYS_TIME_H

#if defined(__GNUC__)
#include_next <sys/time.h>
#else
#include "/usr/include/sys/time.h"
#endif
#include "../repl_select.h"

#endif
