AC_PREREQ(2.65)
AC_INIT([libdicl],
        [0.1.34],
        [daniel.hams@gmail.com])

AC_SUBST(ACLOCAL_AMFLAGS, "-I macros")

AC_CONFIG_SRCDIR(src)
AC_CONFIG_MACRO_DIR(macros)
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([1.9 foreign subdir-objects])
AC_USE_SYSTEM_EXTENSIONS

ABI_VERSION=0.1
AC_SUBST(ABI_VERSION)
AC_DEFINE_UNQUOTED(ABI_VERSION, "$ABI_VERSION", [ABI version of the package])
PACKAGE_SUFFIX="-${ABI_VERSION}"
AC_SUBST(PACKAGE_SUFFIX)
AC_DEFINE_UNQUOTED(PACKAGE_SUFFIX, "$PACKAGE_SUFFIX", [Suffix of the package])

AC_STDC_HEADERS
AC_PROG_CC
AC_PROG_CXX

AX_CXX_COMPILE_STDCXX(17,noext,mandatory)

# Force replacement functions for some known
# broken stuff that isn't auto-detected correctly.
gl_cv_func_select_supports0=no
gl_cv_func_select_detects_ebadf=no
#gl_cv_func_strtod_works=no
#gl_cv_func_strtold_works=no
#gl_cv_func_strtol_works=no
#ac_cv_func_strtol=no
#ac_cv_func_strtoul=no
#ac_cv_func_strtoll=no
#ac_cv_func_strtoull=no
REPLACE_STRFTIME=1
ac_cv_func_strptime=no

gl_EARLY
gl_INIT
AC_PROG_LIBTOOL
PKG_PROG_PKG_CONFIG

#if test yes = '$(lt_cv_prog_gnu_ld)'; then \
#  LIBDICL_USING_GNULD=1; \
#else \
#  LIBDICL_USING_GNULD=0; \
#fi
#AC_SUBST(LIBDICL_USING_GNULD)
AM_CONDITIONAL([LIBDICL_USING_GNULD], [test xyes = x$lt_cv_prog_gnu_ld])

AC_LANG([C])
AC_LANG([C++])

AC_OUTPUT([libdicl.pc
Makefile
src/Makefile
src/repl_headers/Makefile
src/repl_headers/sys/Makefile
src/libdicl/Makefile
gl/Makefile
tests/Makefile])
