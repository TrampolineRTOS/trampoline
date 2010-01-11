target remote 192.168.5.168:2001
file /home/jilias/workspace-arm/trampoline/examples/arm-simtec/trampoline
load

define xipc
display /xi $pc
end

define arm_except
x/1xiw faulty_instruction
p/x saved_psr
p/x interrupted_stack_pointer
end
