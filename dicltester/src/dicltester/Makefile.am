NULL=

bin_PROGRAMS=dicltester

dicltester_SOURCES=			\
	main.c				\
	dicl_printf.c			\
	dicl_select.c			\
	dicl_setenv.c			\
	dicl_strtod.c			\
	$(NULL)

AM_CFLAGS=				\
	$(DICLTESTER_DEPS_CFLAGS)	\
	$(NULL)

dicltester_LDADD=			\
	$(DICLTESTER_DEPS_LIBS)		\
	$(NULL)

CLEANFILES=				\
	.libs				\
	$(NULL)
