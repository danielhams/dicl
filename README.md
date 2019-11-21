# dicl

## Dans Irix Compatibility Library

A little project pulling in some of the gnulib defined functions that can provide better posix / recent libc functionality than IRIX itself has to offer.

There's both the "library" as well as a simple test client application that exercises some of the functionality.

libdicl - The library
dicltester - The client testing application

## How to build/use
Use one of the release builds from github or build it yourself. Using a release will be simpler, as the autoconf bootstrap can take quite some time.

### To use
Add the `libdicl-0.1` installed directory into your project `CPPFLAGS` and add `-ldicl-0.1` to your project `LDFLAGS` or `LIBS` (depends on the builder/project).

### To build
```
cd libdicl
./bootstrap
./configure --prefix=/install/prefix --libdir=/instasll/prefix/lib32
make -j $NUM_JOBS
make install
```

## Issues
Because of the way that libdicl works (override headers for common system things) - tests done by some build tools won't notice the updated / fixed functionality.

As example, `autoconf` based tooling specifically `#undef`s any macros before the feature tests it does. You'll have to override these yourself to ensure you aren't building/using things twice.
