# Trampoline examples for Posix Targets

Have a look to ../README.md to have information about the Posix target (using ViPER).

Basic example with a task that just prints a msg on stdout. 

On linux:
```
goil --target=posix/linux  --templates=../../../goil/templates/ one_task.oil
```

On Mac OS X Intel:
```
goil --target=posix/darwin  --templates=../../../goil/templates/ one_task.oil
```

On Mac OS X Apple Silicon:
```
goil --target=posix/darwin/arm64  --templates=../../../goil/templates/ one_task.oil
```

Then, the makefile is generated, and it will call goil again when the .oil file is updated

```
./make.py
```

Then, run the trampoline binary. This program will start another process to run ViPER silently.

```
./one_task_exe
```

