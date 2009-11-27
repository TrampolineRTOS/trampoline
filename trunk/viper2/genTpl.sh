#!/bin/bash

if [ $# -ne 1 ] && [ $# -ne 2 ];then
  echo "This script is call by "./viper2.py -g"."
  echo "USAGE : $0 <dir> [NODEP]"
  echo ""
  echo -e "\tNODEP : call make with NODEP=1 option"
  exit
fi

NODEP=0
if [ $# -gt 1 ]; then
  if [ $2 == "NODEP" ]; then
    NODEP=1
  fi
fi

cd $1
if [ $NODEP -eq 1 ];then
  rm -f trampoline
fi
# TODO : check if Makefile already exist instead of doing a GOIL every time
if ! [ -f Makefile ]
then
  goil -i -g -t=posix_vp2 --templates=../../../goil/templates/ *.oil
fi
make NODEP=$NODEP

