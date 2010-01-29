#!/bin/sh
set -e
cd `dirname $0` &&
/usr/local/crossgcc/bin/arm-elf-gdb -command=2b-run-in-external-ram.gdb
