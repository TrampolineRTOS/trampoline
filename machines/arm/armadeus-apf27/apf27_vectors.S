.section .exceptionTable
 
.align 2

Vec_undefinedInstruction:  .word primary_undefined_instruction_handler
Vec_softwareInterrupt:     .word tpl_primary_syscall_handler
Vec_prefetchAbort:         .word tpl_primary_prefetch_abort_handler
Vec_dataAbort:             .word tpl_primary_data_abort_handler

