
;@ ------------------------------------------------------------------
;@ ------------------------------------------------------------------

.section .vectbl, "ax"
.code 32
.align 2

@.align 4
.global secureVectors
secureVectors:
  ldr pc,secureVectors_reset_address
  ldr pc,secureVectors_reset_address
  ldr pc,secureVectors_swi_address
  ldr pc,secureVectors_reset_address
  ldr pc,secureVectors_reset_address
  ldr pc,secureVectors_reset_address
  ldr pc,secureVectors_reset_address
  ldr pc,secureVectors_reset_address
secureVectors_reset_address:      .word reset_handler
secureVectors_swi_address:        .word smc_handler
secureVectors_end:

@.align 4
.global vectors
vectors:
  ldr pc,vectors_reset_address
  ldr pc,vectors_undefined_address
  ldr pc,vectors_svc_address
  ldr pc,vectors_prefetch_address
  ldr pc,vectors_data_address
  ldr pc,vectors_reserved_address
  ldr pc,vectors_irq_address
  ldr pc,vectors_undefined_address
vectors_reset_address:      .word reset_handler
vectors_undefined_address:  .word undefined_handler
vectors_svc_address:        .word tpl_primary_syscall_handler
vectors_prefetch_address:   .word prefetch_handler
vectors_data_address:       .word data_handler
vectors_reserved_address:   .word reserved_handler
vectors_irq_address:        .word tpl_primary_irq_handler
vectors_fiq_address:        .word fiq_handler
vectors_end:

.ltorg
