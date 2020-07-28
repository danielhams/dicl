NULL=

SUBDIRS=			\
	sys			\
	$(NULL)

byteswap.h:	$(top_builddir)/gl/byteswap.h
	cp $(top_builddir)/gl/byteswap.h ./

spawn.h:	$(top_builddir)/gl/spawn.h
	cp $(top_builddir)/gl/spawn.h ./

fcntl.h:        $(top_builddir)/gl/fcntl.h
	cp $(top_builddir)/gl/fcntl.h ./

replincludedir=$(includedir)/libdicl@PACKAGE_SUFFIX@

replinclude_HEADERS=		\
	argp.h			\
	byteswap.h		\
	endian.h		\
	error.h			\
	fcntl.h			\
	fnmatch.h		\
	getopt-cdefs.h		\
	getopt-core.h		\
	getopt-ext.h		\
	getopt-pfx-core.h	\
	getopt-pfx-ext.h	\
	getopt.h		\
	obstack.h		\
	regex.h			\
	repl_select.h		\
	spawn.h			\
	stdio.h			\
	stdlib.h		\
	string.h		\
	time.h			\
	unistd.h		\
	$(NULL)
