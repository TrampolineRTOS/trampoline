#!/bin/sh
set -e

cd `dirname $0` &&
ARGUMENT= &&
ARGUMENT="$ARGUMENT -f /usr/local/lib/openocd/interface/arm-usb-ocd.cfg" &&
ARGUMENT="$ARGUMENT -f /usr/local/lib/openocd/target/lpc2294.cfg" &&
ARGUMENT="$ARGUMENT -f /usr/local/arm-dev-files/openocd-scripts/complement.cfg" &&
openocd $ARGUMENT
