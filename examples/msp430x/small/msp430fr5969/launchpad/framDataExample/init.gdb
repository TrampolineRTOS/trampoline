target remote localhost:2000
delete
set *(int*)0x5a0=0xA500
set *(int*)0x5a2=0
x/8hx 0x5a0

