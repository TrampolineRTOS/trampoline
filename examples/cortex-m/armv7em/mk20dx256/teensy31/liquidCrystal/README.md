# liquidCrystal example

A periodic task increments a variable and display it on the LCD. 
The corresponding alarm runs at start.

Have a look at "liquidCrystal.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with:

```
goil --target=cortex-m/armv7em/mk20dx256/teensy31 --templates=../../../../../../goil/templates liquidCrystal.oil
```

Then compile the application:

`./make.py`

If everything went well, program the board (teensy-loader-cli location should be in your path):

`./make.py burn`
