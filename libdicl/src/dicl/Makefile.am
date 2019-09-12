NULL=

dicldir=$(libdir)

dicl_LTLIBRARIES = libdicl@PACKAGE_SUFFIX@.la

libdicl@PACKAGE_SUFFIX@_la_SOURCES=							\
	dicl.c												\
	$(NULL)

libdicl@PACKAGE_SUFFIX@_la_LIBADD=				\
	$(NULL)

diclincludedir=$(includedir)/dicl@PACKAGE_SUFFIX@/dicl

diclinclude_HEADERS=												\
	dicl.h													\
	$(NULL)

CLEANFILES=																\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.o)					\
	$(libdicl@PACKAGE_SUFFIX@_la_SOURCES:.c=.lo)					\
	libdicl@PACKAGE_SUFFIX@.la									\
	libdicl@PACKAGE_SUFFIX@.la									\
	.libs																\
	$(NULL)
