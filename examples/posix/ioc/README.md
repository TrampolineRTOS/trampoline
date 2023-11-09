# Trampoline examples for Posix Targets

Have a look to ../README.md to have information about the Posix target (using ViPER).

Basic example with an IOC (Inter OS-Application Communication).

On linux:
```
goil --target=posix/linux  --templates=../../../goil/templates/ ioc.oil
```

On Mac OS X Intel:
```
goil --target=posix/darwin  --templates=../../../goil/templates/ ioc.oil
```

On Mac OS X Apple Silicon:
```
goil --target=posix/darwin/arm64  --templates=../../../goil/templates/ ioc.oil
```

Then, the makefile is generated, and it will call goil again when the .oil file is updated

```
./make.py
```

Then, run the trampoline binary. This program will start another process to run ViPER silently.

```
./ioc_exe
```

If the trace tools are enabled in OIL file, the execution will create a trace file named "trace.json" and a python script to check the log generated.

```
./readtrace.py
```
