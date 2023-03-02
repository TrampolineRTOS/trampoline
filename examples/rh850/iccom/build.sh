#!/usr/bin/env bash

#stop on errors
set -e

if [[ ! -d "_build" ]]
then
    mkdir _build
fi

echo "*** Run Goil ***"
goil --target=rh850/g4mh --templates=../../../goil/templates/ iccom.oil
cd _build
echo "*** Run CMake ***"
cmake -G "Unix Makefiles" -D CMAKE_TOOLCHAIN_FILE=../iccom/compiler.cmake ..
echo "*** Run Make ***"
make
