tar extended-remote :4242
load
display/x $lr
display/x $pc
display/x $sp
display/x $r0
display/x $r1
display/x $r2
display/x $r3
display/x $r4
display/x IDLE_TASK_int_context
display/x my_periodic_task_int_context
display/x isr_button1_int_context
display/3wx 0xe000e100
display/3wx 0xe000e180
display/3wx 0xe000e200
display/3wx 0xe000e280
display/3wx 0xe000e300
break tpl_primary_irq_handler_EXTI0_IRQ
break tpl_primary_irq_handler_22_EXTI0_IRQ_Handler_exit
break HardFault_Handler
