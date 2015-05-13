tar extended-remote :4242
load
display/x $lr
display/x $pc
display/x $sp
display/16wx $sp
display/19wx isr_button1_stack_zone+31
break HardFault_Handler
break isr_button1_function
