
#include "nxt_spi.h"
#include "interrupts.h"
#include "AT91SAM7.h"

#include "byte_fifo.h"

#include "aic.h"


/*
 * Note that this is not a normal SPI interface, 
 * it is a bodged version as used by the NXT's 
 * display.
 *
 * The display does not use MISO because you can
 * only write to it in serial mode.
 *
 * Instead, the MISO pin is not used by the SPI
 * and is instead driven as a PIO pin for controlling CD.
 *
 * Addional notes from Andy Shaw
 * The following code now contains the capability to perform display
 * updates using dma, This code was inspired by the nxos lcd/spi code
 * (Thanks guys). More details of nxos can be found at:
 * http://nxt.natulte.net/nxos/trac
 *
 */


#define CS_PIN	(1<<10)
#define CD_PIN  (1<<12)
const U8 *display = (U8 *) 0;
volatile U8 dirty = 0;
volatile U8 page = 0;
volatile const U8 *data = (U8 *) 0;
U8 mode = 0xff;

extern void spi_isr_entry(void);

static void spi_set_mode(U8 m)
{
  U32 status;

  /* nothing to do if we are already in the correct mode */
  if (m == mode) return;
  
  /* Wait until all bytes have been sent */
  do {
    status = *AT91C_SPI_SR;
  } while (!(status & 0x200));
  /* Set command or data mode */
  if (m)
    *AT91C_PIOA_SODR = CD_PIN;
  else
    *AT91C_PIOA_CODR = CD_PIN;
  /* remember the current mode */
  mode = m;
}


void spi_isr_C_function(void)
{
  if (page == 0)
  {
    /* Check to see if we have data to display */
    if (dirty != 0)
    {
      data = display;
      dirty = 0;
    }
    else
    {
      /* No so turn things off. It will get re-set if we ever have anything
         to display
      */
      *AT91C_SPI_IDR = AT91C_SPI_ENDTX;
      return;
    }
  }
  /* Make sure we are in data mode */
  spi_set_mode(1);
  /* now do the transfer. We make use of the auto-wrap function so simply
   * need to send 8*132 bytes to get back to where we started. However the
   * display buffer is structured as series of 100 byte lines, so we need to
   * get tricky. I've made the display one line longer (9 lines) and so when we
   * send the data we send 100 bytes from the actual line plus 32 padding bytes
   * (that are not actually seen), from the next line. The extra line means
   * that this is safe to do. If we can redefine the display as a 8*132 then
   * we could just use a single dma transfer (instead of 8, 132 byte ones).
   * However I'm not sure if this would be safe.
   */
  *AT91C_SPI_TNPR = (U32) data;
  *AT91C_SPI_TNCR = 132;
  page = (page + 1) % 8;
  data += 100;
}

extern void tpl_primary_irq_handler(void);

void 
nxt_spi_init(void)
{
  int i_state = interrupts_get_and_disable();
#define OSC 48054805
#define SPI_BITRATE 2000000

  *AT91C_PMC_PCER  =  (1L << AT91C_ID_SPI);       /* Enable MCK clock     */
  *AT91C_PIOA_PER = AT91C_PIO_PA12;/*EnableA0onPA12*/
  *AT91C_PIOA_OER = AT91C_PIO_PA12;
  *AT91C_PIOA_CODR = AT91C_PIO_PA12;
  *AT91C_PIOA_PDR = AT91C_PA14_SPCK;/*EnableSPCKonPA14*/
  *AT91C_PIOA_ASR = AT91C_PA14_SPCK;
  *AT91C_PIOA_ODR = AT91C_PA14_SPCK;
  *AT91C_PIOA_OWER = AT91C_PA14_SPCK;
  *AT91C_PIOA_MDDR = AT91C_PA14_SPCK;
  *AT91C_PIOA_PPUDR = AT91C_PA14_SPCK;
  *AT91C_PIOA_IFDR = AT91C_PA14_SPCK;
  *AT91C_PIOA_CODR = AT91C_PA14_SPCK;
  *AT91C_PIOA_IDR = AT91C_PA14_SPCK;
  *AT91C_PIOA_PDR = AT91C_PA13_MOSI;/*EnablemosionPA13*/
  *AT91C_PIOA_ASR = AT91C_PA13_MOSI;
  *AT91C_PIOA_ODR = AT91C_PA13_MOSI;
  *AT91C_PIOA_OWER = AT91C_PA13_MOSI;
  *AT91C_PIOA_MDDR = AT91C_PA13_MOSI;
  *AT91C_PIOA_PPUDR = AT91C_PA13_MOSI;
  *AT91C_PIOA_IFDR = AT91C_PA13_MOSI;
  *AT91C_PIOA_CODR = AT91C_PA13_MOSI;
  *AT91C_PIOA_IDR = AT91C_PA13_MOSI;
  *AT91C_PIOA_PDR = AT91C_PA10_NPCS2;/*Enablenpcs0onPA10*/
  *AT91C_PIOA_BSR = AT91C_PA10_NPCS2;
  *AT91C_PIOA_ODR = AT91C_PA10_NPCS2;
  *AT91C_PIOA_OWER = AT91C_PA10_NPCS2;
  *AT91C_PIOA_MDDR = AT91C_PA10_NPCS2;
  *AT91C_PIOA_PPUDR = AT91C_PA10_NPCS2;
  *AT91C_PIOA_IFDR = AT91C_PA10_NPCS2;
  *AT91C_PIOA_CODR = AT91C_PA10_NPCS2;
  *AT91C_PIOA_IDR = AT91C_PA10_NPCS2;
  *AT91C_SPI_CR = AT91C_SPI_SWRST;/*Softreset*/
  *AT91C_SPI_CR = AT91C_SPI_SPIEN;/*Enablespi*/
  *AT91C_SPI_MR = AT91C_SPI_MSTR|AT91C_SPI_MODFDIS | (0xB<<16);
  AT91C_SPI_CSR[2] = ((OSC/SPI_BITRATE)<<8) | AT91C_SPI_CPOL;

  /* Set mode to unknown */
  mode = 0xff;

  /* Set up safe dma refresh state */
  data = display = (U8 *) 0;
  dirty = 0;
  page = 0;

  /* Install the interrupt handler */
  aic_mask_off(AT91C_PERIPHERAL_ID_SPI);
  aic_set_vector(AT91C_PERIPHERAL_ID_SPI, AIC_INT_LEVEL_NORMAL,  (U32) tpl_primary_irq_handler);//(U32)spi_isr_entry);
  aic_mask_on(AT91C_PERIPHERAL_ID_SPI);
  *AT91C_SPI_PTCR = AT91C_PDC_TXTEN;

  if (i_state)
    interrupts_enable();

}

void
nxt_spi_write(U32 CD, const U8 *data, U32 nBytes)
{
  U32 status;
  U32 cd_mask = (CD ? 0x100 : 0);

  spi_set_mode(CD);
  while (nBytes) {
    *AT91C_SPI_TDR = (*data | cd_mask);
    data++;
    nBytes--;
    /* Wait until byte sent */
    do {
      status = *AT91C_SPI_SR;
    } while (!(status & 0x200));

  }
}

void
nxt_spi_set_display(const U8 *disp)
{
  /* Set the display buffer to be used for dma refresh.
   * it is really only safe to set the display once. Should probably
   * sort this out so that it is set separately from requesting a refresh
   */
  if (!display) display = disp;
}

void
nxt_spi_refresh(void)
{
  /* Request the start of a dma refresh of the display 
   */
  // If the display is not set nothing to do.
  if (!display) return;
  // Say we have changes
  dirty = 1;
  // Start the DMA refresh
  *AT91C_SPI_IER = AT91C_SPI_ENDTX;
}
