#!/bin/bash

if [ $# -ne 1 ] && [ $# -ne 2 ] && [ $# -ne 3 ];then
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
    opt=$3
  else
    opt=$2
  fi
fi

cd $1
if [ $NODEP -eq 1 ];then
  if [ -f Makefile ]; then
    rm Makefile
  fi
fi

if ! [ -f Makefile ]; then
  goil -i -g -t=posix_vp2 --templates=../../../goil/templates/ *.oil $opt 1>&2
fi

if [ -f Makefile ]; then
  make NODEP=$NODEP
fi

