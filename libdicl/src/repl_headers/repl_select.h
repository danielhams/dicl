#ifndef LIBDICL_REPL_SELECT_H
#define LIBDICL_REPL_SELECT_H

#undef select
#define select rpl_select
extern int rpl_select(int, fd_set *, fd_set *, fd_set *, struct timeval *);

#endif
