#!/bin/sh
set -e

cd `dirname $0` &&
ARGUMENT= &&
ARGUMENT="$ARGUMENT -f /usr/local/lib/openocd/interface/arm-usb-ocd.cfg" &&
ARGUMENT="$ARGUMENT -f olimex-lpc-e2294_14745600.cfg" &&
openocd $ARGUMENT
