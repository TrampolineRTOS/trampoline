#!/bin/sh
cd `dirname $0` && time make --warn-undefined-variables install -j `sysctl -n hw.ncpu`
