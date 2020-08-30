NULL=

bin_PROGRAMS=dicltester

dicltester_SOURCES=			\
	main.c				\
	dicl_printf.c			\
	dicl_fprintf.c			\
	dicl_vsnprintf.c		\
	dicl_select.c			\
	dicl_setenv.c			\
	dicl_strtod.c			\
	dicl_strtof.c			\
	dicl_strtoll.c			\
	dicl_funopencommon.c		\
	dicl_funopenread.c		\
	dicl_funopenwrite.c		\
	$(NULL)

AM_CFLAGS=				\
	-Wall                           \
	-pthread			\
	$(DICLTESTER_DEPS_CFLAGS)	\
	$(NULL)

dicltester_LDADD=			\
	$(DICLTESTER_DEPS_LIBS)		\
	-lpthread			\
	-ldiclfunopen-0.1		\
	$(NULL)

CLEANFILES=				\
	.libs				\
	$(NULL)
