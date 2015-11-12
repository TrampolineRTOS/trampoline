#!/bin/sh
set -e

cd `dirname $0` &&
ARGUMENT= &&
ARGUMENT="$ARGUMENT -f olimex-arm-usb-ocd.cfg" &&
ARGUMENT="$ARGUMENT -f olimex-lpc-l2294-1Mo.cfg" &&

SUDO_ON_LINUX="" &&
if [ `uname -s` \= Linux ] ; then
  SUDO_ON_LINUX="sudo"
fi &&
$SUDO_ON_LINUX /usr/local/bin/openocd $ARGUMENT
