NULL=

SUBDIRS=			\
	sys			\
	$(NULL)

byteswap.h:	$(top_srcdir)/gl/byteswap.h
	cp $(top_srcdir)/gl/byteswap.h ./

spawn.h:	$(top_srcdir)/gl/spawn.h
	cp $(top_srcdir)/gl/spawn.h ./

replincludedir=$(includedir)/libdicl@PACKAGE_SUFFIX@

replinclude_HEADERS=		\
	argp.h			\
	byteswap.h		\
	endian.h		\
	error.h			\
	fnmatch.h		\
	getopt-cdefs.h		\
	getopt-core.h		\
	getopt-ext.h		\
	getopt-pfx-core.h	\
	getopt-pfx-ext.h	\
	getopt.h		\
	obstack.h		\
	repl_select.h		\
	spawn.h			\
	stdio.h			\
	stdlib.h		\
	string.h		\
	unistd.h		\
	$(NULL)
