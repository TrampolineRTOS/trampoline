#!/bin/sh
cd `dirname $0` && make --warn-undefined-variables -f makefile64 all -j `sysctl -n hw.ncpu`
