#!/usr/bin/env bash

set -e

PROGRAM_NAME=can_demo

echo "*** Run Goil ***"
mkdir -p _build
goil --target=rh850/g4mh --templates=../../../goil/templates/ ${PROGRAM_NAME}.oil

echo "*** Run CMake ***"
cd _build
cmake -G "Unix Makefiles" -D CMAKE_TOOLCHAIN_FILE=../${PROGRAM_NAME}/compiler.cmake ..

echo "*** Run Make ***"
make
