NULL=

dicldir=$(libdir)

dicl_LTLIBRARIES =						\
	libdicl@PACKAGE_SUFFIX@.la				\
	libdiclfunopen@PACKAGE_SUFFIX@.la			\
	$(NULL)

libdicl@PACKAGE_SUFFIX@_la_SOURCES=				\
	libdicl.c						\
	strtod.c						\
	strtold.c						\
	strtol.c						\
	strtoll.c						\
	strtoul.c						\
	strtoull.c						\
	c-ctype.c						\
	$(NULL)

libdicl@PACKAGE_SUFFIX@_la_LIBADD=				\
	$(NULL)

libdiclfunopen@PACKAGE_SUFFIX@_la_SOURCES=			\
	funopen_replacements.cpp				\
	$(NULL)

libdiclfunopen@PACKAGE_SUFFIX@_la_LIBADD=			\
	libdicl@PACKAGE_SUFFIX@.la				\
	-lnsl							\
	$(NULL)

if LIBDICL_USING_GNULD
LIBDICL_LDFLAGS=-Wl,--export-dynamic,--whole-archive,$(top_builddir)/gl/libgnu.a,--no-whole-archive
else
LIBDICL_LDFLAGS=-Wl,-all,$(top_builddir)/gl/libgnu.a
endif

libdicl@PACKAGE_SUFFIX@_la_LDFLAGS=				\
	$(LIBDICL_LDFLAGS)					\
	-lpthread						\
	$(NULL)

diclincludedir=$(includedir)/libdicl@PACKAGE_SUFFIX@/libdicl

diclinclude_HEADERS=						\
	libdicl.h						\
	c-ctype.h						\
	funopen_replacements.h					\
	$(NULL)

CLEANFILES=							\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.o)		\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.lo)		\
	$(libdiclfunopen@PACKAGE_SUFFIX@_la_SOURCES:.cpp=.o)	\
	$(libdiclfunopen@PACKAGE_SUFFIX@_la_SOURCES:.cpp=.lo)	\
	libdicl@PACKAGE_SUFFIX@.la				\
	libdiclfunopen@PACKAGE_SUFFIX@.la			\
	.libs							\
	$(NULL)
