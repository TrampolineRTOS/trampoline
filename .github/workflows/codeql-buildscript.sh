#!/usr/bin/env bash

ROOT_DIR=$PWD

cd "$ROOT_DIR/goil/makefile-unix/"
./build.py release
GOIL="$ROOT_DIR/goil/makefile-unix/goil"
export GOIL_TEMPLATES="$ROOT_DIR/goil/templates"

# Not needed if we do not actually run the apps
#cd viper && make && cd -

for app in $(find "$ROOT_DIR/examples/posix/" -mindepth 1 -maxdepth 1 -type d); do
  cd "$app"
  $GOIL --target=posix/linux *.oil
  ./make.py
  ./make.py clean
done

#for app in $(find "$ROOT_DIR/examples/arm/nxt" -mindepth 1 -maxdepth 1 -type d); do
#  cd "$app"
#  $GOIL --target=arm/nxt *.oil
#  ./make.py
#  ./make.py clean
#done

cd $ROOT_DIR/examples/cortex/armv7m/SmartFusion2/starterKit/fpgaInterrupt
$GOIL --target=cortex/armv7m/SmartFusion2 *.oil
./make.py; ./make.py clean

cd $ROOT_DIR/examples/cortex/armv7m/SmartFusion2/starterKit/blink
$GOIL --target=cortex/armv7m/SmartFusion2 *.oil
./make.py; ./make.py clean

cd $ROOT_DIR/examples/cortex/armv7m/atsam3x8e/arduino_due/blink
$GOIL --target=cortex/armv7m/atsam3x8e/arduino_due *.oil
./make.py; ./make.py clean

for app in $(find "$ROOT_DIR/examples/cortex/armv7em/mk20dx256/teensy31" -mindepth 1 -maxdepth 1 -type d); do
  cd "$app"
  $GOIL --target=cortex/armv7em/mk20dx256/teensy31 *.oil
  ./make.py; ./make.py clean
done
