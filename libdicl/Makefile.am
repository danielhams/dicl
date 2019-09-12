NULL=

SUBDIRS=							\
	.								\
	gl								\
	src								\
	tests							\
	$(NULL)

ACLOCAL_AMFLAGS=-I macros -I gl/m4

pkgconfigdir=$(libdir)/pkgconfig

pkgconfig_DATA=libdicl@PACKAGE_SUFFIX@.pc

libdicl@PACKAGE_SUFFIX@.pc:	libdicl.pc
	cp $< $@

libdiclincludedir=$(includedir)/dicl@PACKAGE_SUFFIX@
libdiclinclude_HEADERS=						\
	$(NULL)

EXTRA_DIST=											\
	libdicl.pc.in								\
	gl/m4/gnulib-cache.m4						\
	$(NULL)

CLEANFILES=											\
	libdicl@PACKAGE_SUFFIX@.pc				\
	$(NULL)

DISTCLEANFILES=$(CLEANFILES)						\
	$(NULL)
