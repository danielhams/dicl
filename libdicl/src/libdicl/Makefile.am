NULL=

dicldir=$(libdir)

dicl_LTLIBRARIES = libdicl@PACKAGE_SUFFIX@.la

# Not yet sure how to express this dependency
#libdicl@PACKAGE_SUFFIX@.la: $(top_srcdir)/gl/libgnu.a

libdicl@PACKAGE_SUFFIX@_la_SOURCES=				\
	libdicl.c						\
	$(NULL)

libdicl@PACKAGE_SUFFIX@_la_LIBADD=				\
	$(NULL)

if LIBDICL_USING_GNULD
LIBDICL_LDFLAGS=-Wl,--export-dynamic,--whole-archive,$(top_srcdir)/gl/libgnu.a,--no-whole-archive
else
LIBDICL_LDFLAGS=-Wl,-all,$(top_srcdir)/gl/libgnu.a
endif

libdicl@PACKAGE_SUFFIX@_la_LDFLAGS=				\
	$(LIBDICL_LDFLAGS)					\
	$(NULL)

diclincludedir=$(includedir)/libdicl@PACKAGE_SUFFIX@/libdicl

diclinclude_HEADERS=						\
	libdicl.h						\
	$(NULL)

CLEANFILES=							\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.o)		\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.lo)		\
	libdicl@PACKAGE_SUFFIX@.la				\
	libdicl@PACKAGE_SUFFIX@.la				\
	.libs							\
	$(NULL)
