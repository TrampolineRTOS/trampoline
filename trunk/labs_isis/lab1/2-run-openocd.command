#!/bin/sh
set -e

cd `dirname $0` &&
ARGUMENT= &&
ARGUMENT= &&
ARGUMENT="$ARGUMENT -f /usr/local/share/openocd/scripts/interface/arm-usb-ocd.cfg" &&
ARGUMENT="$ARGUMENT -f /usr/local/dev-arm/arm-dev-files/openocd-scripts/olimex-lpc-h2294_14745600.cfg" &&
openocd $ARGUMENT
