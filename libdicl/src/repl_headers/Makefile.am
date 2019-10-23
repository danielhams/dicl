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
	error.h			\
	repl_select.h		\
	spawn.h			\
	stdio.h			\
	stdlib.h		\
	string.h		\
	unistd.h		\
	$(NULL)
