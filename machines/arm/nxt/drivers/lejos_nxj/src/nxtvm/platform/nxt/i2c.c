
/*
 * This file implements the software-based I2C for accessing I2C
 * devices via the sensor ports.
 */

#include "i2c.h"
#include "AT91SAM7.h"
#include "interrupts.h"
#include "aic.h"
#include "systick.h"

#include <string.h>

#define I2C_MAX_PARTIAL_TRANSACTIONS 3
#define I2C_N_PORTS 4

struct i2c_pin_pair {
  U32 scl;
  U32 sda;
};
static const struct i2c_pin_pair i2c_pin[4] = {
  {1 << 23, 1 << 18},
  {1 << 28, 1 << 19},
  {1 << 29, 1 << 20},
  {1 << 30, 1 << 2}
};

// A partial transaction has the following form:
// 1. Possibly starts with a start bit (which might be a restart).
// 2. Has 1 or more bytes (read or write)
// 3. Possibly has a stop bit.

// A transaction has the following form:
// 1. One to 3 partial transactions.

// Some examples:
//
//  Transaction to write a single byte to an address will have one
//  partial transaction:
//  0:   Start. Tx two bytes, address + data. Stop
//
//
//  Transaction to read one byte from an address will have two 
//  partial transactions:
//  0: Start. Tx one address byte.
//  1: Read byte. Stop.
//
//  Transaction to write some bytes to a particular internal address at an address:
//
//  0: Start. Send address + internal address.
//  1: Restart. Send address + data bytes. Stop.
//
//  Transaction to read some bytes from a particular internal address at an address:
//
//  0: Start. Send address + internal address.
//  1: Restart. Send address.
//  2: Read data. Stop.
//
// Note: It appears that the Lego ultrasonic sensor needs a 
// stop and an extra clock before the restart.
//
// Additional changes made by Andy Shaw...
//
// Port 4 on the nxt is a little odd. It has extra hardware to implement
// an RS485 interface. However this interacts with the digital I/O lines
// which means that the original open collector driver used in this code
// did not work. The code now uses a combination of open collector drive
// on the clock lines (with pull up resistors enabled), plus a fully
// driven ineterface on the data lines. This differs from the Lego
// firmware which uses a fully driven clock inetrface. However doing so
// means that it is hard (or impossible), to operate with the devices
// that make use of clock stretching. It is hoped that the compromise
// implemented here will work with all devices.


struct i2c_partial_transaction {
  U8  start:1;	
  U8  restart:1;
  U8  stop:1;	
  U8  tx:1;	
  U8  last_pt:1; // Last pt in transaction
  U16 nbytes;	// N bytes to transfer
  U8* data;	// Data buffer
};

typedef enum {
  I2C_UNINITIALISED = 0,
  I2C_IDLE,
  I2C_BEGIN,
  I2C_RESTART1,
  I2C_START1,
  I2C_START2,
  I2C_START3,
  I2C_START_RECLOCK1,
  I2C_LOW0,
  I2C_LOW1,
  I2C_HIGH0,
  I2C_HIGH1,
  I2C_STOP0,
  I2C_STOP1,
  I2C_STOP2,
  I2C_STOP3,
} i2c_port_state;

struct i2c_port_struct {
  U32 scl_pin;
  U32 sda_pin;
  U8  addr_int[2]; /* Device ddress with internal address */
  U8  addr;	   /* Just device address */
  struct i2c_partial_transaction partial_transaction[I2C_MAX_PARTIAL_TRANSACTIONS];
  struct i2c_partial_transaction *current_pt;

  i2c_port_state state;

  U32 nbits;
  U32 ack_slot;
  U32 ack_slot_pending;
  U8  *data;
  U32 transmitting;
  U32 fault;
  U32 n_fault;
  U32 n_good;
  U32 ack_fail;
  U32 ack_good;
  U32 pt_num;
  U32 pt_begun;
};

static struct i2c_port_struct i2c_port[I2C_N_PORTS];



// Some logging code trying to debug the ulttasonic sensor.
#if 0
#define I2C_LOG_N 200
static U8 i2c_logb[I2C_LOG_N];
static U32 i2c_logn;
static void i2c_log(int port, int state, int inpin)
{
  static U32 last_valid;
  if(i2c_logn < I2C_LOG_N &&
     (state > I2C_IDLE || last_valid) &&
     port == 0){
     i2c_logb[i2c_logn] = state | (inpin ?  0x10 : 0);
     i2c_logn++;
     last_valid = (state > I2C_IDLE);
  }
}

#else
#define i2c_log(a,b,c) do{ } while(0)
#endif



// The I2C state machines are pumped by a timer interrupt
// running at 4x the bit speed.

static U32 i2c_int_count;

extern void i2c_timer_isr_entry(void);

void i2c_timer_isr_C_function(void)
{
  int i;


  U32 codr = 0;
  U32 sodr = 0;
  U32 oer = 0;
  U32 odr = 0;
  U32 inputs = *AT91C_PIOA_PDSR;

  struct i2c_port_struct *p = i2c_port;

  U32 dummy = *AT91C_TC0_SR;

  i2c_int_count++;
  
  for (i = 0; i < I2C_N_PORTS; i++) {

    i2c_log(i,p->state, inputs & p->sda_pin);
    
    switch (p->state) {
    default:
    case I2C_UNINITIALISED:	// Uninitialised
      break;
    case I2C_IDLE:		// Not in a transaction
      break;
    case I2C_BEGIN:		
      // Start the current partial transaction
      p->pt_begun |= (1 << p->pt_num);
      oer |= p->sda_pin;
      oer |= p->scl_pin;
      
      if(p->current_pt && p->current_pt->nbytes){
        p->data = p->current_pt->data;
        p->nbits = p->current_pt->nbytes * 8;
        p->transmitting = p->current_pt->tx;
        p->ack_slot = 0;
        p->ack_slot_pending = 0;
        p->fault = 0;
        
        if(!p->transmitting)
          *(p->data) = 0;

        if(p->current_pt->restart){
          // Make sure both SDA and SCL are high
          sodr |= p->scl_pin;
          sodr |= p->sda_pin;
          p->state = I2C_RESTART1;
        } else if(p->current_pt->start){
          sodr |= p->sda_pin;
          p->state = I2C_START1;
        }
        else {
          codr |= p->scl_pin;
          p->state = I2C_LOW0;
        }
      }
      else {
        p->state = I2C_IDLE;
      }
      break;
    case I2C_RESTART1:
      // SDA high, take SCL Low
      codr |= p->scl_pin;
      p->state = I2C_START1;
      break;
    case I2C_START1:
      // SDA high, take SCL high
      sodr |= p->scl_pin;
      p->state = I2C_START2;
      break;
    case I2C_START2:		
      if(inputs & p->sda_pin){
        // Take SDA low while SCL is high
        codr |= p->sda_pin;
        p->state = I2C_START3;
      }
      else {
        // SDA was not high, so do a clock
        codr |= p->scl_pin;
        p->state = I2C_START_RECLOCK1;
      }
      break;
    case I2C_START_RECLOCK1:
      codr |= p->scl_pin;
      p->state = I2C_START1;
      break;
    case I2C_START3:
      // Take SCL low
      codr |= p->scl_pin;
      p->state = I2C_LOW0;
      break;
    case I2C_LOW0:
      // SCL is low
      if(p->ack_slot_pending){
        p->ack_slot = 1;
        p->ack_slot_pending = 0;
      }
      else
        p->ack_slot = 0;

      if(p->nbits || p->ack_slot){
        if(p->ack_slot) {
        
          if(p->transmitting)
            odr |= p->sda_pin;
          else
          {
            oer |= p->sda_pin;
            codr |= p->sda_pin;
          }
        
        } else if(!p->transmitting)
          odr |= p->sda_pin;
        else {
          // Transmitting, and not an ack slot so send next bit
          oer |= p->sda_pin;
          p->nbits--;
          if(((*(p->data)) >> (p->nbits & 7)) & 0x01)
            sodr |= p->sda_pin;
          else
            codr |= p->sda_pin;
          
          if((p->nbits & 7) == 0){
            p->data++;
            if(p->nbits || p->transmitting)
              p->ack_slot_pending = 1;
          }
        }
        p->state = I2C_LOW1;
      
      } else if(p->current_pt->stop){
        p->state = I2C_STOP0;
      } else {
        p->current_pt++;
        p->pt_num++;
        sodr |= p->sda_pin;
        p->state = I2C_BEGIN;
      }
      break;
    case I2C_LOW1:
      // Take SCL high
      sodr |= p->scl_pin;
      p->state = I2C_HIGH0;
      break;
    case I2C_HIGH0:
      // Wait for high pulse width
      // If someone else is not holding the pin down, then advance
      if(inputs & p->scl_pin)
        p->state = I2C_HIGH1;
      break;
    case I2C_HIGH1:
      if(p->transmitting && p->ack_slot){
        // Expect ack from slave
        if(inputs & p->sda_pin){
          p->n_fault++;
          p->ack_fail++;
          p->fault=1;
          codr |= p->scl_pin;
          p->state = I2C_STOP0;
        }
        else {
          p->ack_good++;
          codr |= p->scl_pin;        
          p->state = I2C_LOW0;
        }
      }
      
      else {
        // Read pin if needed, then take SCL low
        
        if(!p->transmitting && !p->ack_slot){
          // Receive a bit.
          U8 *d = p->data;
          p->nbits--;
          if(inputs & p->sda_pin)
            *d |= (1 << (p->nbits & 7));
        
          if(p->nbits && ((p->nbits & 7) == 0)){
            p->data++;
            d = p->data;
            p->ack_slot_pending = 1;
            *d = 0;
          }
        }

        codr |= p->scl_pin;        
        p->state = I2C_LOW0;
        
      }
      break;
    case I2C_STOP0:
      // Take SDA low (SCL is already low)
      oer |= p->sda_pin;
      codr |= p->sda_pin;
      p->state = I2C_STOP1;
      break;  
    case I2C_STOP1:
      // Take SCL high
      sodr |= p->scl_pin;
      p->state = I2C_STOP2;
      break;
    case I2C_STOP2:
      // Take SDA pin high
      sodr |= p->sda_pin;
      p->state = I2C_STOP3;
      break;
    case I2C_STOP3:
      if(p->current_pt->last_pt){
        p->state = I2C_IDLE;
      } else {
        p->current_pt++;
        p->pt_num++;
        p->state = I2C_BEGIN;
      }
    }

    p++;

  }

  if (codr)
    *AT91C_PIOA_CODR = codr;
  if (sodr)
    *AT91C_PIOA_SODR = sodr;
  if (oer)
    *AT91C_PIOA_OER = oer;
  if (odr)
    *AT91C_PIOA_ODR = odr;
}


// Disable an I2C port
void
i2c_disable(int port)
{
  if (port >= 0 && port < I2C_N_PORTS) {
    struct i2c_port_struct *p = &i2c_port[port];
    U32 pinmask = p->scl_pin | p->sda_pin;

    *AT91C_PIOA_ODR = pinmask;
  }
}

// Enable an I2C port
void
i2c_enable(int port)
{
  if (port >= 0 && port < I2C_N_PORTS) {
    struct i2c_port_struct *p = &i2c_port[port];
    U32 pinmask = p->scl_pin | p->sda_pin;
    p->state = I2C_IDLE;
    /* Set clock pin for output, open collector driver, with
     * pullups enabled. Set data to be enabled for output with
     * pullups disabled.
     */
    *AT91C_PIOA_SODR  = pinmask;
    *AT91C_PIOA_OER   = pinmask;
    *AT91C_PIOA_MDER  = p->scl_pin;
    *AT91C_PIOA_PPUDR = p->sda_pin;
    *AT91C_PIOA_PPUER = p->scl_pin;
  }
}

extern void tpl_primary_irq_handler(void);

// Initialise the module
void
i2c_init(void)
{
  int istate;
  U32 dummy;  
  {
    int i;
    struct i2c_port_struct *p = i2c_port;

    for (i = 0; i < I2C_N_PORTS; i++) {
      p->state = I2C_IDLE;
      p->scl_pin = i2c_pin[i].scl;
      p->sda_pin = i2c_pin[i].sda;
      i2c_disable(i);
      p++;
    }
  }
  
  istate = interrupts_get_and_disable();
  
  /* Set up Timer Counter 0 */
  *AT91C_PMC_PCER = (1 << AT91C_ID_TC0);    /* Power enable */
    
  *AT91C_TC0_CCR = 0x02; /* Disable */
  *AT91C_TC0_IDR = ~0;
  dummy = *AT91C_TC0_SR;
  *AT91C_TC0_CMR = 0x4000; /* MCLK/2, RC compare trigger */
  *AT91C_TC0_RC = (CLOCK_FREQUENCY/2)/(4 * 9600);
  *AT91C_TC0_IER = 0x10; /* Enable RC trigger interrupt */
  *AT91C_TC0_CCR = 1; /* Enable */

  aic_mask_off(AT91C_ID_TC0);
  aic_set_vector(AT91C_ID_TC0, AIC_INT_LEVEL_NORMAL,  (U32) tpl_primary_irq_handler);//i2c_timer_isr_entry);
  aic_mask_on(AT91C_ID_TC0);
  
  *AT91C_TC0_CCR = 0x04; /* Software trigger */
  
  if(istate)
    interrupts_enable();
}


// Is the port busy?
int
i2c_busy(int port)
{
  if(port >= 0 && port < I2C_N_PORTS)
    return (i2c_port[port].state > I2C_IDLE);
  return 0;
}

/* Start a transaction. 
 */
int
i2c_start_transaction(int port, 
                      U32 address, 
                      int internal_address, 
                      int n_internal_address_bytes, 
                      U8 *data, 
                      U32 nbytes,
                      int write)
{ 
  struct i2c_port_struct *p;
  struct i2c_partial_transaction *pt;
  if(port < 0 || port >= I2C_N_PORTS)
    return -1;
    
  if(i2c_busy(port))
    return -1;
    
  p = &i2c_port[port];
  p->pt_num = 0;
  p->pt_begun = 0;
  pt = p->partial_transaction;
  p->current_pt = pt;
  
  memset(pt,0,sizeof(p->partial_transaction));
  
  
  if(n_internal_address_bytes > 0){
    // Set up command to write the internal address to the device
    p->addr_int[0] = (address << 1); // This is a write
    p->addr_int[1] = internal_address;
  
    // Set up first partial transaction: start address and internal address if required

    pt->start = 1;
    // We add an extra stop for the odd Lego i2c sensor, but only on a read
    pt->stop = (write ? 0 : 1);;
    pt->tx = 1;
    pt->data = p->addr_int;
    pt->nbytes = 2;
    
    pt++;
  }

  if(n_internal_address_bytes == 0 || !write){  
    // Set up second partial transaction: restart and address
    pt->start = (n_internal_address_bytes > 0) ? 0 : 1;
    pt->restart = !pt->start;
    pt->stop = 0;
    pt->tx = 1;
    p->addr = (address << 1) | (write ? 0 : 1);
    pt->data = &p->addr;
    pt->nbytes = 1;
  
    pt++;
  }
  
  // Set up third partial transaction: data and stop
  pt->start = 0;
  pt->stop = 1;
  pt->tx = (write ? 1 : 0);
  pt->data = data;
  pt->nbytes = nbytes;
  pt->last_pt = 1;

  // Start the transaction
  p->state = I2C_BEGIN;
  
  return 0;
}

// Test

#if 0
#include "nxt_avr.h"
void i2c_test(void)
{ U8 xx[20];
  int result;
  nxt_avr_set_input_power(0,2);
  i2c_enable(0);
  while(1){
    systick_wait_ms(1000);
    i2c_start_transaction(0,1,0,1,xx,4,0);
    //i2c_start_transaction(0,1,0x42,1,xx,1,0);
    systick_wait_ms(1000);
    result = i2c_busy(0);
  }
}
#endif
