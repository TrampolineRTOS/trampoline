#!/usr/bin/env bash

#stop on errors
set -e

if [[ ! -d "_build" ]]
then
    mkdir _build
fi

echo "*** Run Goil ***"
goil --target=rh850/g4mh --templates=../../../goil/templates/ memory_unlocker.oil
cd _build
echo "*** Run CMake ***"
cmake -G "Unix Makefiles" -D CMAKE_TOOLCHAIN_FILE=../memory_unlocker/compiler.cmake ..
echo "*** Run Make ***"
make
