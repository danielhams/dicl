#!/bin/sh

rm -rf COPYING INSTALL aclocal.m4 autom4te.cache config.guess config.h.in config.sub configure install-sh ltmain.sh missing config.h.in~ Makefile Makefile.in config.h config.log config.status lib*.pc depcomp compile libtool src/.deps src/Makefile src/Makefile.in stamp-h1 macros/libtool.m4 macros/lt*.m4 config.rpath test-driver
# These get left when extra sources directories get added under src
find . -name "\.deps" -exec rm -rf {} \;
find . -name "*~" -exec rm -f {} \;
find . -name "Makefile\.in" -exec rm -f {} \;
find . -name "Makefile" -exec rm -f {} \;
