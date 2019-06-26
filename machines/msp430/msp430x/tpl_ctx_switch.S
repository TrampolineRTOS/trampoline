#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
/*#include "tpl_os_kernel_stack.h"*/

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

#define CTX_GPR4    8
#define CTX_GPR5    10
#define CTX_GPR6    12
#define CTX_GPR7    14
#define CTX_GPR8    16
#define CTX_GPR9    18
#define CTX_GPR10   20
#define CTX_GPR11   22
#define CTX_GPR12   24
#define CTX_GPR13   26
#define CTX_GPR14   28
#define CTX_GPR15   30


.global tpl_save_context
.type   tpl_save_context, %function

tpl_save_context:

    /*popx    0(r4)


    popx    
    push    r2, #CTX_GPR4(r1)*/
    ret

.global tpl_load_context
.type   tpl_load_context, %function

tpl_load_context:
    ret

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"