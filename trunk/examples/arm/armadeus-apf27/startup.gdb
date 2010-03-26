target remote 192.168.5.168:2001
load

define xipc
display /xi $pc
end

define arm_except
x/1xiw faulty_instruction
p/x saved_psr
p/x interrupted_stack_pointer
end
