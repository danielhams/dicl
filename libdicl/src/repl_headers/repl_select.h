#ifndef LIBDICL_REPL_SELECT_H
#define LIBDICL_REPL_SELECT_H

#if defined(__GNUC__)
#include_next <unistd.h>
#include_next <sys/types.h>
#include_next <bstring.h>
#include_next <sys/time.h>
#include_next <sys/signal.h>
#else
#include "/usr/include/unistd.h"
#include "/usr/include/sys/types.h"
#include "/usr/include/bstring.h"
#include "/usr/include/sys/time.h"
#include "/usr/include/sys/signal.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#undef select
#define select rpl_select
extern int rpl_select(int, fd_set *, fd_set *, fd_set *, struct timeval *);

/* New - pselect for irix */
#define pselect rpl_pselect
extern int rpl_pselect(int, fd_set *, fd_set *, fd_set *,
		       const struct timespec *restrict,
		       const sigset_t *restrict);

#if defined(__cplusplus)
}
#endif

#endif
