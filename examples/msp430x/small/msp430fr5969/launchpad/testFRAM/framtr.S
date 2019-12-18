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

.global saveCheckpoint
.type   saveCheckpoint, %function
/*
 * Save a part of the SRAM in the FRAM as a checkpoint.
 * r15 contains the buffer to use for checkpoint (0 or 1)
 */
.extern __data_start
.extern _end
.extern DMA0SA

saveCheckpoint:
  cmp     #2, r15             /* check the buffer is valid (0 or 1)     */
  jhs     exit_saveCheckPoint
  swpb    r15                 /* 000000000000000x -> 0000000x00000000   */
  rlam    #3, r15             /* 0000000x00000000 -> 0000x00000000000   */
  addx.a  #0x10000, r15       /* 00010000x00000000000 start of FRAM buf */
  mov     #_end, r13          /* end of the data in SRAM                */
  mov     #__data_start, r14  /* origin of the SRAM                     */
  sub     r14, r13            /* size in bytes                          */
  tst     #1, r13             /* test odd                               */
  jz      even_size
  inc     r13
even_size:
  clrc
  rrc     r13                 /* size in words                          */

  sub
  mov     r14, &DMA0SA        /* source start address is SRAM origin    */
  movx.a  r15, &DMA0DA        /* dest start address is FRAM buffer      */

exit_saveCheckPoint:
  ret
