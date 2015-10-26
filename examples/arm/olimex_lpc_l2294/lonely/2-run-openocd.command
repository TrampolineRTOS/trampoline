#!/bin/sh
set -e

cd `dirname $0` &&
ARGUMENT= &&
ARGUMENT="$ARGUMENT -f /usr/local/share/openocd/scripts/interface/arm-usb-ocd.cfg" &&
ARGUMENT="$ARGUMENT -f /usr/local/dev-arm/arm-dev-files/openocd-scripts/olimex-lpc-e2294_14745600.cfg" &&

SUDO_ON_LINUX="" &&
if [ `uname -s` \= Linux ] ; then
  SUDO_ON_LINUX="sudo"
fi &&
$SUDO_ON_LINUX /usr/local/bin/openocd $ARGUMENT
