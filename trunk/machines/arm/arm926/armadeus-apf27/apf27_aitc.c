#include "apf27_aitc.h"

typedef volatile struct
{
  u32 INTCTL;
  u32 NIMASK;
  u32 INTENNUM;
  u32 INTDISNUM;
  u32 INTENABLEH;
  u32 INTENABLEL;
  u32 INTTYPEH;
  u32 INTTYPEL;
  u32 NIPRIORITY[8];
  u32 NIVECSR;
  u32 FIVECSR;
  u32 INTSRCH;
  u32 INTSRCL;
  u32 INTFRCH;
  u32 INTFRCL;
  u32 NIPNDH;
  u32 NIPNDL;
  u32 FIPNDH;
  u32 FIPNDL;
} AITC_registers_map;

#define AITC (*((AITC_registers_map *)0x10040000))

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern void tpl_primary_irq_handler (void);

void apf27_aitc_init ()
{
  u32 i;
  u32 *target;

  /*
   * All defaults to 0 :
   * - no interrupt mask
   * - no special treatment for bus arbitration
   * - vectors in high memory
   */
  AITC.INTCTL = 0;
  /* no interrupt mask */
  AITC.NIMASK = -1;

  /* we enable only interrupt sources that are declared in OIL file,
   * more interrupt sources can be enabled later via 
   * apf27_aitc_enable_source_int
   */
#if ISR_COUNT > 0
  for (i = 0 ; i < 64 ; i++)
  {
    /* if corresponding vector is not connected to NULL,
     * this means that we need this source, so we enable it
     */
    if (tpl_it_vector[i].func != tpl_null_it)
      AITC.INTENNUM = i;
  }
#endif /* ISR_COUNT > 0 */
  
  /* All interrupts sources are routed to nIRQ (and not FIQ) */
  AITC.INTTYPEH = 0;
  AITC.INTTYPEL = 0;

  /* All interrupts sources gets priority level 0 */
  for (i = 0 ; i < 8 ; i++)
    AITC.NIPRIORITY[i] = 0;

  /* all vectors points on the primary IRQ handler */
  /* TODO: i.MX vector table would be useful if it would point
   * on the right routine */
  target = (u32*)0xFFFFFF00;
  for (i = 0 ; i < 64 ; i++)
  {
    *target = (u32)&tpl_primary_irq_handler;
    target++;
  }
}

void apf27_aitc_set_source_int_level (IMX27_interrupt_source source, u32 level)
{
  u32 source_number;
  u32 reg_num;
  u32 decal;

  source_number = (u32)source;
  reg_num = source_number >> 3;
  decal = source_number & 7;
  decal = decal << 2;

  AITC.NIPRIORITY[reg_num] = level << decal;
}

void apf27_aitc_enable_source_int (IMX27_interrupt_source source)
{
  u32 source_number;

  source_number = (u32)source;

  AITC.INTENNUM = source_number;
}

void apf27_aitc_disable_source_int (IMX27_interrupt_source source)
{
  u32 source_number;

  source_number = (u32)source;

  AITC.INTDISNUM = source_number;
}

void apf27_aitc_force_source_int (IMX27_interrupt_source source)
{
  u32 source_number;
  u32 reg_num;
  u32 decal;

  source_number = (u32)source;
  reg_num = source_number >> 5;
  decal = source_number & 31;

  if (reg_num == 0)
    AITC.INTFRCL |= 1 << decal;
  else
    AITC.INTFRCH |= 1 << decal;
}

IMX27_interrupt_source apf27_aitc_get_source_int (void)
{
  return (IMX27_interrupt_source)((AITC.NIVECSR >> 16 )& 0xFFFF);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

