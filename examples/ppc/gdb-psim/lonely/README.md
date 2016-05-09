# Lonely example

## Example
This application is a simple example with a task that is activated at startup.

It is based on the PowerPC simulator that is embbeded with gdb. No interrupts are available.

Have a look into "blink.oil" file.

## Build prerequiste

You should have: 

 * A cross-compiler suite (based on gcc): `powerpc-elf-gcc`

## Build

Configure the application with:

```
goil --target=ppc/psim --templates=../../../../goil/templates/ lonely.oil 
```

The `goil` compiler generates the `make.py` [python build script](https://github.com/TrampolineRTOS/trampoline/wiki/Application-Build-system). Then run the script:

```
./make.py all
```

The `lonely_exe` should be generated. 

Then run the powerPC application directly with gdb. The `.gdbinit` script provided just load the binary.

```
powerpc-elf-gdb
```

## Clean

Use the `clean` target of the make.py:

```
./make.py clean
```