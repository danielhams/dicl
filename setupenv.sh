export DGR=/usr/didbs/0_1_3_n32_mips4_mp/gbs4_2
#export DGR=/usr/didbs/0_1_3_n32_mips4_mp/gbs5_0
export CC=gcc
export CXX=g++
export CPPFLAGS="-D_SGI_SOURCE -D_SGI_REENTRANT_FUNCTIONS"
export CFLAGS="--std=c99 -g -O0 -mips4"
#export CFLAGS="-g -O0 -mips4"
export CXXFLAGS="$CFLAGS"
export LDFLAGS="-mips4 -L/usr/didbs/0_1_3_n32_mips4_mp/lib32 -L$DGR/lib32"
export LD_LIBRARYN32_PATH=/usr/people/dan/DacepsInstall/lib32:$LD_LIBRARYN32_PATH
export PKG_CONFIG_PATH=/usr/people/dan/DiclInstall/lib/pkgconfig:$PKG_CONFIG_PATH
