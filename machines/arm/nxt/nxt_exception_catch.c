/**
 * @file nxt_exception_catch.c
 *
 * @section descr File description
 *
 * First part of the bootstrap for NXT
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
#include "display.h"
#include "AT91SAM7.h"

U32 exception_catch_pc = 0;
U32 saved_psr = 0;
U32 exception_catch_id = 0;

void
exception_catch_display(void)
{
    display_clear(0);
    display_goto_xy(0, 0);
    switch (exception_catch_id)
    {
        case 1:
            display_string("Prefetch abort");            
            break;
        case 2:
            display_string("Data abort");
            break;
        case 3:
            display_string("Undefined instruction");
            break;
        case 4:
            display_string("Unused");
            break;
        default:
            display_string("Exception Undef");
            break;
    }
    display_goto_xy(0, 1);
    display_string("PC   ");
    display_hex(exception_catch_pc, 8);
    display_goto_xy(0, 2);
    display_string("MSR   ");
    display_hex(saved_psr, 8);
    /*display_goto_xy(0, 2);
    display_string("AASR ");
    display_hex(*AT91C_MC_AASR, 8);
    display_goto_xy(0, 3);
    display_string("ASR  ");
    display_hex(*AT91C_MC_ASR, 8);*/

    //  display_update();
    display_force_update();

  while (1) {
  }
}

/* End of file nxt_exception_catch.c */
