#!/bin/sh
set -e
cd `dirname $0` &&
arm-none-eabi-gdb -command=2b-run-in-external-ram.gdb
