target remote localhost:2000
layout split
set print pretty on
delete
b main
c
delete
b 54
c
set *0x442=0
delete
#b tpl_primary_irq_handler_TIMER3_A0_VECTOR
#c
#info registers
#set $sp=0xA1111
#set $sr=0xA2222
#set $cg=0xA3333
set $r4=0xA4444
set $r5=0xA5555
set $r6=0xA6666
set $r7=0xA7777
set $r8=0xA8888
set $r9=0xA9999
set $r10=0x3AAAA
set $r11=0xABBBB
set $r12=0xACCCC
set $r13=0xADDDD
set $r14=0xAEEEE
set $r15=0xAFFFF

b buttonS1_function
c
delete