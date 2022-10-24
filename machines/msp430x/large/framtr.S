#include "tpl_app_define.h"
#if WITH_CHECKPOINTING == YES
#define OS_START_SEC_CODE
#include "AsMemMap.h"

.global framUpWrite16
.type   framUpWrite16, %function
/*
 * write a 16 bits word in FRAM
 * Address is in register r15
 * data is in r14
 */
framUpWrite16:
  /* build up a 20 bits in r15 by adding 0x10000 */
  addx.a #0x10000,r15
  movx   r14, @r15
  ret

.global framUpRead16
.type   framUpRead16, %function
/*
 * read a 16 bits word from FRAM
 * Address is in register r15
 * data is return in r15
 */
framUpRead16:
  /* build up a 20 bits in r15 by adding 0x10000 */
  addx.a #0x10000,r15
  movx   @r15, r15
  ret

.global framUpWrite8
.type   framUpWrite8, %function
/*
 * write a byte in FRAM
 * Address is in register r15
 * data is in r14
 */
framUpWrite8:
  /* build up a 20 bits in r15 by adding 0x10000 */
  addx.a #0x10000,r15
  movx.b r14, @r15
  ret

.global framUpRead8
.type   framUpRead8, %function
/*
 * read a byte from FRAM
 * Address is in register r15
 * data is return in r15
 */
framUpRead8:
  /* build up a 20 bits in r15 by adding 0x10000 */
  addx.a #0x10000,r15
  movx.b @r15, r15
  ret


/*
 * Checkpointing functions
 */
.extern __data_start
.extern __tpl_end_of_checkpointing_zone
.extern _chkptStartAddress_0
.extern _chkptStartAddress_1

.extern DMA0SA
.extern DMA0DA
.extern DMA0SZ

.set DMADT_1,       0x1000
.set DMASRCINCR_3,  0x0300
.set DMADSTINCR_3,  0x0C00
.set DMASWDW,       0x0000
.set DMAEN,         0x0010
.set DMAREQ,        0x0001

.global tpl_save_checkpoint_dma
.type   tpl_save_checkpoint_dma, %function
/*
 * Save a part of the SRAM in the FRAM as a checkpoint.
 * r15 contains the buffer to use for checkpoint (0 or 1)
 *
 * Checkpoint buffers are located at addresses 0x40000 and 0x42000 and
 * are 8kB in size each
 *   addx.a  #0x10000, r15      0001 000x 0000 0000 0000 start of FRAM buf   
 */
tpl_save_checkpoint_dma:
  cmp     #2, r12                 /* check the buffer is valid (0 or 1)     */
  jhs     exit_saveCheckpoint
  clrc
  cmp     #0, r12
  jz      is_chkpt_0_save
  inc     r12
  swpb    r12               /* 0000 0000 0000 0010 -> 0000 0010 0000 0000   */
  rlam    #4, r12           /* 0000 0010 0000 0000 -> 0010 0000 0000 0000   */
is_chkpt_0_save:
  addx.a  #0x40000, r12     /* 0100 00x0 0000 0000 0000 start of FRAM buf   */
  mov     #__tpl_end_of_checkpointing_zone, r13 /* end of the data in SRAM  */
  mov     #__data_start, r14      /* origin of the SRAM                     */
  sub     r14, r13                /* size in bytes                          */
  bit     #1, r13                 /* test odd                               */
  jz      even_size_saveCheckpoint
  inc     r13
even_size_saveCheckpoint:
  clrc
  rrc     r13                     /* size in words                          */

  mov     r14, &DMA0SA            /* source start address is SRAM origin    */
  movx.a  r12, &DMA0DA            /* dest start address is FRAM buffer      */
  mov     r13, &DMA0SZ            /* size of the transfer                   */
  /*
   * Launch the transfer:
   * DMADT_1           Block transfer mode
   * DMASRCINCR_3      Source address incremented
   * DMADSTINCR_3      Destination address incremented
   * DMASWDW           Word transfer
   * DMAEN             Enable
   * DMAREQ            Launch transfer
   */
  mov     #DMADT_1|DMASRCINCR_3|DMADSTINCR_3|DMASWDW|DMAEN|DMAREQ, &DMA0CTL

exit_saveCheckpoint:
  reta

.global tpl_load_checkpoint_dma
.type   tpl_load_checkpoint_dma, %function
/*
 * Load a part of the SRAM from the FRAM as a checkpoint.
 * r15 contains the buffer to use for checkpoint (0 or 1)
 *
 * Checkpoint buffers are located at addresses 0x40000 and 0x42000 and
 * are 8kB in size each
 *   addx.a  #0x10000, r15      0001 000x 0000 0000 0000 start of FRAM buf   
 */
tpl_load_checkpoint_dma:
  cmp     #2, r12                 /* check the buffer is valid (0 or 1)     */
  jhs     exit_loadCheckpoint
  clrc
  cmp     #0, r12
  jz      is_chkpt_0_load
  inc     r12
  swpb    r12               /* 0000 0000 0000 0010 -> 0000 0010 0000 0000   */
  rlam    #4, r12           /* 0000 0010 0000 0000 -> 0010 0000 0000 0000   */
is_chkpt_0_load:
  addx.a  #0x40000, r12     /* 0100 00x0 0000 0000 0000 start of FRAM buf   */
  mov     #__tpl_end_of_checkpointing_zone, r13 /* end of the data in SRAM  */
  mov     #__data_start, r14      /* origin of the SRAM                     */
  sub     r14, r13                /* size in bytes                          */
  bit     #1, r13                 /* test odd                               */
  jz      even_size_loadCheckpoint
  inc     r13
even_size_loadCheckpoint:
  clrc
  rrc     r13                     /* size in words                          */

  movx.a  r12, &DMA0SA            /* source start address is FRAM buffer    */
  mov     r14, &DMA0DA            /* dest start address is SRAM origin      */
  mov     r13, &DMA0SZ            /* size of the transfer                   */
  /*
   * Launch the transfer:
   * DMADT_1           Block transfer mode
   * DMASRCINCR_3      Source address incremented
   * DMADSTINCR_3      Destination address incremented
   * DMASWDW           Word transfer
   * DMAEN             Enable
   * DMAREQ            Launch transfer
   */
  mov     #DMADT_1|DMASRCINCR_3|DMADSTINCR_3|DMASWDW|DMAEN|DMAREQ, &DMA0CTL

exit_loadCheckpoint:
  reta

#define OS_STOP_SEC_CODE
#include "AsMemMap.h"
#endif //WITH_CHECKPOINTING
