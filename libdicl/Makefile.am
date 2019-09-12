NULL=

SUBDIRS=							\
	.								\
	src								\
	$(NULL)

ACLOCAL_AMFLAGS=-I macros

pkgconfigdir=$(libdir)/pkgconfig

pkgconfig_DATA=libdicl@PACKAGE_SUFFIX@.pc

libdicl@PACKAGE_SUFFIX@.pc:	libdicl.pc
	cp $< $@

libdiclincludedir=$(includedir)/dicl@PACKAGE_SUFFIX@
libdiclinclude_HEADERS=						\
	$(NULL)

EXTRA_DIST=											\
	libdicl.pc.in								\
	$(NULL)

CLEANFILES=											\
	libdicl@PACKAGE_SUFFIX@.pc				\
	$(NULL)

DISTCLEANFILES=$(CLEANFILES)						\
	$(NULL)
