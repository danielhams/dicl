AC_PREREQ(2.65)
AC_INIT([libdicl],
        [0.1.0],
        [daniel.hams@gmail.com])

AC_SUBST(ACLOCAL_AMFLAGS, "-I macros")

AC_CONFIG_SRCDIR(src)
AC_CONFIG_MACRO_DIR(macros)
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([1.9 dist-bzip2 no-dist-gzip foreign subdir-objects])

ABI_VERSION=0.1
AC_SUBST(ABI_VERSION)
AC_DEFINE_UNQUOTED(ABI_VERSION, "$ABI_VERSION", [ABI version of the package])
PACKAGE_SUFFIX="-${ABI_VERSION}"
AC_SUBST(PACKAGE_SUFFIX)
AC_DEFINE_UNQUOTED(PACKAGE_SUFFIX, "$PACKAGE_SUFFIX", [Suffix of the package])

AC_STDC_HEADERS
AC_PROG_CC
gl_EARLY
gl_INIT
AC_PROG_LIBTOOL
PKG_PROG_PKG_CONFIG

AC_LANG([C])
AC_LANG([C++])

AC_OUTPUT([libdicl.pc
Makefile
src/Makefile
src/libdicl/Makefile
gl/Makefile
tests/Makefile])
