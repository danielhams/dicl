#ifndef LIBDICL_FNMATCH_H
#define LIBDICL_FNMATCH_H

#if defined(__GNUC__)
#include_next <fnmatch.h>
#else
#include "/usr/include/fnmatch.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/* We #undef these before defining them because some losing systems
   (HP-UX A.08.07 for example) define these in <unistd.h>.  */
#undef  FNM_PATHNAME
#undef  FNM_NOESCAPE
#undef  FNM_PERIOD
#undef  FNM_NOMATCH

/* Bits set in the FLAGS argument to 'fnmatch'.  */
#define FNM_PATHNAME    (1 << 0) /* No wildcard can ever match '/'.  */
#define FNM_NOESCAPE    (1 << 1) /* Backslashes don't quote special chars.  */
#define FNM_PERIOD      (1 << 2) /* Leading '.' is matched only explicitly.  */

# define FNM_FILE_NAME   FNM_PATHNAME   /* Preferred GNU name.  */
# define FNM_LEADING_DIR (1 << 3)       /* Ignore '/...' after a match.  */
# define FNM_CASEFOLD    (1 << 4)       /* Compare without regard to case.  */
# define FNM_EXTMATCH    (1 << 5)       /* Use ksh-like extended matching. */

/* Value returned by 'fnmatch' if STRING does not match PATTERN.  */
#define FNM_NOMATCH     1

/* This value is returned if the implementation does not support
   'fnmatch'.  Since this is not the case here it will never be
   returned but the conformance test suites still require the symbol
   to be defined.  */
# define FNM_NOSYS      (-1)

#undef fnmatch
#define fnmatch rpl_fnmatch
extern int rpl_fnmatch(const char *, const char *, int);

#if defined(__cplusplus)
}
#endif

#endif
