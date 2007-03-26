#!/bin/sh
cd `dirname $0` && time make --warn-undefined-variables -f makefile64 all
