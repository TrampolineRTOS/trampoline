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
    mov         22(r1), r14         /* Saved PC [19..16] */
    mov         20(r1), 22(r1)      /* Copy saved PC [15..0] at the good place */
    swpb        r14                 /* Get saved PC [19..16] in bits 11..8 */
    rlam.w      #4, r14             /* Shift them to bits 19..16 */
    bis         r2, r14             /* Add the SR in its location at 11..0 */
    mov         r14, 20(r1)         /* The stack is ok */
/* the rest of the context is saved on the process stack */
    pushm.a     #7, r10             /* push r4 to r10 */
/* The whole context is now saved on the process stack and the kernel stack has been cleaned 
   the stack pointer is saved in the dedicated location */
    mov         &tpl_kern, r11      /* Get the s_running slot of tpl_kern in r11 */
    mov         @r11, r11           /* Get the pointer to the context (SP alone) */
    mov         r1, @r11 
    ret

.global tpl_load_context
.type   tpl_load_context, %function

tpl_load_context:
    ret

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"