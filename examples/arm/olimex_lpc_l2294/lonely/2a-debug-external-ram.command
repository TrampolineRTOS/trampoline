#!/bin/sh
set -e
cd `dirname $0` &&
arm-none-eabi-gdb -command=2b-debug-in-external-ram.gdb
