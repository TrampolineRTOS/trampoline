#!/bin/sh
cd `dirname $0` && make --warn-undefined-variables all -j `sysctl -n hw.ncpu`
