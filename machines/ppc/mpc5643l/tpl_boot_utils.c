/*
 * @file tpl_assembler.h
 *
 * @section desc File description
 *
 * C functions used by MPC5643L boot
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

/*
 * TODO : tpl_copy_init_data should be defined for each supported compiler
 */

#include "tpl_os_std_types.h"
#include "tpl_os.h"

#define OS_START_SEC_BOOT
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_clear_bss(uint32* bss_start, uint32* bss_end)
{
    while((uint32)bss_start < (uint32)bss_end)
    {
        *(bss_start++) = 0;
    }
}

#if defined (__CSMC__)
#define MOVEABLE_SEGMENT_FLAG 0x60000000

typedef struct _csmic_idata_desc_ {
    uint8* rom_address;
    uint32 flag_word;
    uint8* ram_address;
} csmic_idata_desc;


FUNC(void, OS_CODE) tpl_copy_init_data(csmic_idata_desc* desc)
{
    uint32 flag_word;
    uint8* ram_addr;
    uint8* rom_addr;
    uint8* rom_end_addr;

    while(1){
        /* Check if there is another segment */
        flag_word = desc[0].flag_word;
        if(!flag_word) break; /* Return if there is no more segments */

        /* Check if this segment is a text moveable segment */
        if(!(flag_word & MOVEABLE_SEGMENT_FLAG)) {
            /* Ignore moveable segments */
            desc++;
            continue;
        }

        /* Get Rom & Ram addresses and copy the segment byte per byte */
        rom_addr = desc[0].rom_address;
        ram_addr = desc[0].ram_address;
        rom_end_addr = desc[1].rom_address;

        while((uint32)rom_addr != (uint32)rom_end_addr)
        {
            *(ram_addr++) = *(rom_addr++);
        }

        /* Next segment */
        desc++;
    }
}
#else

FUNC(void, OS_CODE) tpl_copy_init_data(csmic_idata_desc* desc){
    /* Undefined compiler */
    return void;
}

#endif

#define OS_STOP_SEC_BOOT
#include "tpl_memmap.h"

