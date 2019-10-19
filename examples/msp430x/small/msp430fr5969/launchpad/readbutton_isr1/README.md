#readbutton isr1 example

The task ```blink``` is activated by the alarm ```blink_alarm```.
The task ```blink``` toggles the GREEN led whenever it is executed.

A GPIO interrupt leads to the execution of an ISR1 that toggle the RED led.

Have a look into ```readbutton_isr1.oil``` file.

The system is based scheduled with a 1ms SysTick ```SystemCounter```.
 
Configure the application with:

```sh
goil --target=msp430x/small/msp430fr5969/launchpad --templates=../../../../../../goil/templates/ readbutton_isr1.oil
```

then

```sh
./make.py
```

to compile the application

```sh
./make.py flash
```

To upload it to the board.