#include "flashprog.h"
#include "interrupts.h"
#include "twi.h"
#include "systick.h"
#include "nxt_avr.h"
#include "at91sam7s256.h"

// Timeouts in ms
#define TWI_TIMEOUT 5
#define FLASH_TIMEOUT 20

static U32 get_ms()
{
  /* Return a timer value in ms that can be used while interrupts are disabled
   * NOTE: This function must be here (rather then in systick), because it is
   * called during a flash write and so must be located in ram, not flash rom.
   */
  // We use the missed interupt count from the system timer
  return (*AT91C_PITC_PIIR & AT91C_PITC_PICNT) >> 20;
}
 
static int wait_flash_ready()
{
  // Wait for the flash controller to be ready or to timeout. Note although
  // we implement a timeout operation, it is not clear what to do if we
  // ever get one. If the system is still trying to write to flash then
  // it may not be possible to execute code from flash...
  int status;
  int timeout = get_ms() + FLASH_TIMEOUT;
  do {
    status = *AT91C_MC_FSR;
    if (status & AT91C_MC_FRDY) return status;
  } while (get_ms() < timeout);
  return status;
}

static int wait_twi_complete()
{
  int status;
  int timeout = systick_get_ms() + TWI_TIMEOUT;
  do {
    status = twi_status();
    if (status <= 0) return status;
  } while (systick_get_ms() < timeout);
  return status;
}

int
flash_write_page(int start_page, U32 *page, int page_num)
{
  int i, istate;
  int status;
  
  if (page_num + start_page > 1023) return 0;
  
  systick_suspend();
   	
  systick_wait_ms(1);
 
  nxt_avr_1kHz_update();
 
  // modified based on the latest leJOS source (April 16th takashic)
  // Wait for it to complete
  status = wait_twi_complete();
  if (status != 0) return -1;
  // Now we can turn off all ints
  istate = interrupts_get_and_disable();

  for (i = 0; i < 64; i++)
    FLASH_BASE[(page_num*64)+i] = page[i];

  FLASH_CMD_REG = (0x5A000001 + (((page_num + start_page) & 0x000003FF) << 8));

  status = wait_flash_ready();
  
  // modified based on the latest leJOS source (April 16th takashic)
  // Turn ints back on
  if (istate) interrupts_enable();
  // Ensure that we are back in-sync.
  systick_wait_ms(1);
  // Allow call backs on 1ms tick
  systick_resume();
  if (!(status & AT91C_MC_FRDY)) return -1;
  return 1;
}

void flash_set_mode(U32 fmcn) {
  FLASH_MODE_REG = ((fmcn << 16) | (1 << 8));
}

void
flash_erase_range(U32 addr, U32 nBytes)
{
  int i = 0;
  int istate = interrupts_get_and_disable();

  while (nBytes--) {
    i++;
  }
  if (istate)
    interrupts_enable();
}

void
flash_write(U32 addr, void *buffer, U32 nBytes)
{
  int i = 0;
  int istate = interrupts_get_and_disable();

  while (nBytes--) {
    i++;
  }
  if (istate)
    interrupts_enable();
}
