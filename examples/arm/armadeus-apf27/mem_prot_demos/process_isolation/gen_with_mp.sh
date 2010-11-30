#!/bin/sh
goil --autosar --generate-makefile --target=arm/arm926/armadeus-apf27 --templates=../../../../../goil/templates with_mp.oil
make
