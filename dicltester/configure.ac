AC_PREREQ(2.65)
AC_INIT([dicltester],
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
AC_PROG_LIBTOOL
PKG_PROG_PKG_CONFIG

AC_LANG([C])

AC_MSG_CHECKING([whether libdicl should be used])
AC_ARG_ENABLE([libdicl-replacements],
	[AS_HELP_STRING([--enable-libdicl-replacements],[use libdicl replacements])],
	[],
	[enable_libdicl_replacements=yes])
AC_MSG_RESULT([$enable_libdicl_replacements])

LIBDICL_VERSION=0.1
AC_SUBST(LIBDICL_VERSION)

PACKAGE_DEPENDENCY_LIST="libdicl-$LIBDICL_VERSION >= $LIBDICL_VERSION"
AC_DEFINE_UNQUOTED(PACKAGE_DEPENDENCY_LIST, "$PACKAGE_DEPENDENCY_LIST", [Package dependency list])

if test "x$enable_libdicl_replacements" = xyes; then
   PKG_CHECK_MODULES([DICLTESTER_DEPS], [$PACKAGE_DEPENDENCY_LIST])
   USE_LIBDICL=yes
   AC_DEFINE_UNQUOTED(USE_LIBDICL,[1], [Whether to use replacements])
fi

AC_OUTPUT([Makefile
src/Makefile
src/dicltester/Makefile])
