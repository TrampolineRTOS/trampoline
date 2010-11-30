#!/bin/sh
goil --autosar --generate-makefile --target=arm/arm926/armadeus-apf27 --templates=../../../../../goil/templates without_mp.oil
make
