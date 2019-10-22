NULL=

SUBDIRS=			\
	sys			\
	$(NULL)

argp.h:		$(top_srcdir)/gl/argp.h
	cp $(top_srcdir)/gl/argp.h ./

spawn.h:	$(top_srcdir)/gl/spawn.h
	cp $(top_srcdir)/gl/spawn.h ./

replincludedir=$(includedir)/libdicl@PACKAGE_SUFFIX@

replinclude_HEADERS=		\
	argp.h			\
	repl_select.h		\
	spawn.h			\
	stdio.h			\
	stdlib.h		\
	unistd.h		\
	$(NULL)
