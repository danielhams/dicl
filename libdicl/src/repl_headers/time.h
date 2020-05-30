#ifndef LIBDICL_TIME_H
#define LIBDICL_TIME_H

#if defined(__GNUC__)
#include_next <time.h>
#else
#include "/usr/include/time.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

  /* Missing pieces */
  time_t timegm(struct tm *tm);

#if defined(__cplusplus)
}
#endif

#endif
