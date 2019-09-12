NULL=

dicldir=$(libdir)

dicl_LTLIBRARIES = libdicl@PACKAGE_SUFFIX@.la

libdicl@PACKAGE_SUFFIX@_la_SOURCES=							\
	libdicl.c												\
	$(NULL)

libdicl@PACKAGE_SUFFIX@_la_LIBADD=				\
	$(NULL)

diclincludedir=$(includedir)/libdicl@PACKAGE_SUFFIX@/libdicl

diclinclude_HEADERS=												\
	libdicl.h													\
	$(NULL)

CLEANFILES=																\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.o)					\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.lo)					\
	libdicl@PACKAGE_SUFFIX@.la									\
	libdicl@PACKAGE_SUFFIX@.la									\
	.libs																\
	$(NULL)
