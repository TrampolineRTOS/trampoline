tar extended-remote :4242
load
display/x $lr
display/x $pc
display/x $sp
display/x $r0
display/x $r1
display/x $r2
display/x $r3
display/8wx $msp
display/x tabMainStack
break tpl_primary_syscall_handler
