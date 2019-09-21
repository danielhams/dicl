#ifndef LIBDICL_UNISTD_H
#define LIBDICL_UNISTD_H

#if defined(__GNUC__)
#include_next <unistd.h>
#else
#include "/usr/include/unistd.h"
#endif
#include "repl_select.h"

#endif
