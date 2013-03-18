#!/bin/sh
set -e
cd `dirname $0` &&
arm-elf-gdb -command=2b-debug-in-internal-ram.gdb
