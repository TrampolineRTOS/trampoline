#include "tpl_assembler.h"

#if defined (__GNUC__)
TPL_GLOBAL(__eabi)
TPL_GLOBAL_REF(__eabi):
    se_blr
    se_nop
#endif