# Trampoline examples for Posix Targets

Have a look to ../README.md to have information about the Posix target (using ViPER).

Basic example with interrupts: signals are sent with keystroke 'a' and 'b'. Exit with 'q'

On linux:
```
goil --target=posix/linux  --templates=../../../goil/templates/ isr.oil
```

On Mac OS X Intel:
```
goil --target=posix/darwin  --templates=../../../goil/templates/ isr.oil
```

On Mac OS X Apple Silicon:
```
goil --target=posix/darwin/arm64  --templates=../../../goil/templates/ isr.oil
```

Then, the makefile is generated, and it will call goil again when the .oil file is updated

```
./make.py
```

Then, run the trampoline binary. This program will start another process to run ViPER silently.

```
./isr_exe
```

If the trace tools are enabled in OIL file, the execution will create a trace file named "trace.json" and a python script to check the log generated.

```
./readtrace.py
```
