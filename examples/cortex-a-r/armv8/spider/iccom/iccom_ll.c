#include "iccom_ll.h"
#include "iodefine.h"
#include <string.h>
//#include "Compiler.h"
#include "tpl_compiler.h"

uint32 ICCOM_CTA_MEMORY_CH0 = 0x47fc7000;
uint32 ICCOM_CTA_MEMORY_CH1 = 0x47fc9000;

#define GICD_ISENABLER     (0xf0000100)

void iccom_ll_init(void)
{
	volatile uint32 val = 0;

	/* Disable MFIS write protection */
	MFIS0.MFISWPCNTR = 0xACCE0001;
	do {
		val = MFIS0.MFISWPCNTR;
	} while (val != 0x00000001);

	/* Enable Iccom interrupt (id 353)*/
	uint32 int_d = 353;
	*((volatile uint32 *)(GICD_ISENABLER + 4 * (int_d / 32)))  = 1 << (int_d % 32);
}

static void iccom_lock(ICCOM_CHANNEL channel)
{
	/* nothing at the moment */
}

static void iccom_unlock(ICCOM_CHANNEL channel)
{
	/* nothing at the moment */
}

/**
 * Set MFIS CPU communication control register [i] G4MH[k] core to Cortex-A55
 * CPU core(MFISAM[k]EICR[i])(i=0-7)(k=0-1).
 *
 * Support only CPU 0 to G4MH 0
 */
void iccom_set_out_ctrl_reg(uint32 val)
{
	MFIS0.MFISAREICR0 = val;
}

/**
 * Get MFIS CPU communication control register [i] G4MH[k] core to Cortex-A55
 * CPU core(MFISAM[k]EICR[i])(i=0-7)(k=0-1).
 *
 * Support only CPU 0 to G4MH 0
 */
void iccom_get_out_ctrl_reg(uint32 *pval)
{
	volatile uint32 reg = 0;
	reg = MFIS0.MFISAREICR0;

	if (NULL_PTR != pval) {
		*pval = reg;
	}
}

/**
 * Clear the interruption bit
 *
 * MFIS CPU communication control register [i] Cortex-A55 CPU core to G4MH[k]
 * core(MFISAM[k]IICR[i])(i=0-7)(k=0-1)
 *
 * Support only CPU 0 to G4MH 0
 */
void iccom_clear_interrupt(void)
{
	volatile uint32 reg = 0;
	reg = MFIS0.MFISARIICR0;
	reg &= ~(ICCOM_CTRL_INT);
	MFIS0.MFISARIICR0 = reg;
}

/**
 * Get MFIS CPU communication control register [i] Cortex-A55 CPU core to G4MH[k]
 * core(MFISAM[k]IICR[i])(i=0-7)(k=0-1)
 *
 * Support only CPU 0 to G4MH 0
 */
void iccom_get_in_ctrl_reg(uint32 *pval)
{
	volatile uint32 reg = 0;
	reg = MFIS0.MFISARIICR0;

	if (NULL_PTR != pval) {
		*pval = reg;
	}
}

void iccom_set_in_ctrl_reg(uint32 val)
{
	MFIS0.MFISARIICR0 = val;
}

/**
 * Set MFIS CPU communication message register [i] G4MH[k] core to Cortex-A55
 * CPU core(MFISAM[k]EMBR[i])(i=0-7)(k=0-1)
 *
 * Support only CPU 0 to G4MH 0
 */
void iccom_set_out_msg_reg(uint32 val)
{
	MFIS0.MFISAREMBR0 = val;
}

/**
 * Get MFIS CPU communication message register [i] Cortex-A55 CPU core to
 * G4MH[k] core(MFISAM[k]IMBR[i])(i=0-7)(k=0-1)
 *
 * Support only CPU 0 to G4MH 0
 */
void iccom_get_in_msg_reg(uint32 *pval)
{
	volatile uint32 reg = 0;
	reg = MFIS0.MFISARIMBR0;

	if (NULL_PTR != pval) {
		*pval = reg;
	}
}

void iccom_clear_interrupt_locked(void)
{
	iccom_lock(ICCOM_CHANNEL_0);

	iccom_clear_interrupt();

	iccom_unlock(ICCOM_CHANNEL_0);
}

void iccom_cta_write(uint8 * buff, size_t size)
{
	void* ctaPtr = (void*)ICCOM_CTA_MEMORY_CH1;

	if (buff == NULL_PTR)
		return;

	memcpy(ctaPtr, buff, size);
}

void iccom_cta_read(uint8 * buff, size_t size)
{
	void* ctaPtr = (void*)ICCOM_CTA_MEMORY_CH0;

	if (buff == NULL)
		return;

	memcpy(buff, ctaPtr, size);
}

uint8* iccom_get_read_cta_ptr()
{
	return (uint8*)ICCOM_CTA_MEMORY_CH0;
}

uint8* iccom_cta_write_cta_ptr()
{
	return (uint8*)ICCOM_CTA_MEMORY_CH1;
}
