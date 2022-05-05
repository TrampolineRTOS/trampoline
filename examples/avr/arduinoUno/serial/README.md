Basic example with the serial line (115200 bauds, 8N1)

First compile your application (oil+compilation):

```sh
goil --target=avr/arduino/uno --templates=../../../../goil/templates/ serial.oil
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
