Basic example with another TIMER for counter interrupt.

First compile your application (oil+compilation):

```sh
goil --target=avr/arduino/uno --templates=../../../../goil/templates/ counter.oil
```
then compilation:
```
./make.py
```

Then upload the example (simple blink task):
```sh
export AVRDUDE_PORT="/dev/ttyACM0"
./make.py flash
```
