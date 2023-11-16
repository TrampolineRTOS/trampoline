#!/usr/bin/env bash

#stop on errors
set -e

if [[ ! -d "_build" ]]
then
    mkdir _build
fi

echo "*** Run Goil ***"
goil --target=cortex-a-r/armv8/spider --templates=../../../../../goil/templates/ eth.oil

echo "*** Run Make ***"
./make.py
