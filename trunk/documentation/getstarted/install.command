#!/bin/sh
set -x

DIR=`dirname $0` && cd $DIR &&
#---
BINUTILS_VERSION=binutils-2.19.1 &&
GCC_VERSION=gcc-4.4.1 &&
NEWLIB_VERSION=newlib-1.17.0 &&
GDB_VERSION=gdb-6.8 &&
#INSTALL_DIR=$DIR/TEMP &&
INSTALL_DIR=/usr/local/gcc-for-arm/gcc-4-4-1 &&
USE_SUDO="sudo" &&
#---
rm -f *.tar &&

#--- Binutils
echo "----------- CROSS COMPILING BINUTILS"
rm -fr build-binutils $BINUTILS_VERSION &&
bunzip2 -kc $BINUTILS_VERSION.tar.bz2 > $BINUTILS_VERSION.tar &&
tar xf $BINUTILS_VERSION.tar &&
rm -f *.tar &&
mkdir build-binutils &&
cd build-binutils &&
../$BINUTILS_VERSION/configure --help &&
../$BINUTILS_VERSION/configure --prefix=$INSTALL_DIR --target=arm-elf --disable-werror "CC=gcc-4.0 -m32" &&
time make all &&
$USE_SUDO make install &&
cd .. &&
rm -fr build-binutils $BINUTILS_VERSION &&

#--- GCC
echo "----------- CROSS COMPILING GCC"
rm -fr build-gcc $GCC_VERSION $NEWLIB_VERSION &&
bunzip2 -kc $GCC_VERSION.tar.bz2 > $GCC_VERSION.tar &&
tar xf $GCC_VERSION.tar &&
bunzip2 -kc $NEWLIB_VERSION.tar.bz2 > $NEWLIB_VERSION.tar &&
tar xf $NEWLIB_VERSION.tar &&
rm -f *.tar &&
mv $NEWLIB_VERSION $GCC_VERSION/ &&
mkdir build-gcc &&
cd build-gcc &&
../$GCC_VERSION/configure --help &&
../$GCC_VERSION/configure --prefix=$INSTALL_DIR --target=arm-elf --with-newlib --enable-languages=c --disable-libssp --disable-werror "CC=gcc-4.0 -m32" &&
time make all &&
$USE_SUDO make install &&
cd .. &&
rm -fr build-gcc $GCC_VERSION &&

#--- GDB
echo "----------- CROSS COMPILING GDB"
rm -fr build-gdb $GDB_VERSION &&
bunzip2 -kc $GDB_VERSION.tar.bz2 > $GDB_VERSION.tar &&
tar xf $GDB_VERSION.tar &&
rm -f *.tar &&
mkdir build-gdb &&
cd build-gdb &&
../$GDB_VERSION/configure --help &&
../$GDB_VERSION/configure --prefix=$INSTALL_DIR --target=arm-elf --disable-werror "CC=gcc-4.0 -m32" &&
time make all &&
$USE_SUDO make install &&
cd .. &&
rm -fr build-gdb $GDB_VERSION &&
#---
echo "----------- Success!"
