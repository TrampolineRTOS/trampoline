# Trampoline CAN demo example

Have a look to ../README.md for more information about the POSIX target (using ViPER).

This example allows to test the Trampoline CAN stack on the development PC.

On Linux:
```
goil --target=posix/linux  --templates=../../../goil/templates/ can_demo.oil
```

On Mac OS X Intel:
```
goil --target=posix/darwin  --templates=../../../goil/templates/ can_demo.oil
```

On Mac OS X Apple Silicon:
```
goil --target=posix/darwin/arm64  --templates=../../../goil/templates/ can_demo.oil
```

Then, the makefile is generated, and it will call goil again when the .oil file
is updated.
```
./make.py
```

Then, run the trampoline binary.
```
VIPER_PATH=../../../viper/ ./can_demo_exe
```

To quit, run the command below from another terminal.
```
killall -SIGINT can_demo_exe
```
