#!/bin/sh
cd `dirname $0` && time make --warn-undefined-variables all -j `sysctl -n hw.ncpu`
