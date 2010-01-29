/*
 * This module handles communications between the NXT main ARM processor and
 * the AVR processor. The AVR provides support for the motors, analogue sensors
 * keyboard and power. The two processors are linked via a TWI connection. This
 * is used to exchange a message every 1ms. The message alternates between
 * sending commands to the AVR and receiving status from it.
 * NOTES:
 * The time window for read requests is very tight. On some NXT devices it can
 * be exceeded. This code has been optimized to maximize the read window and
 * to handle the times that the window is exceeded.
 */
#include "nxt_avr.h"


#include "twi.h"
#include "nxt_motors.h"

#include "systick.h"
#include <string.h>
#include "display.h"
#include "at91sam7s256.h"

#define NXT_AVR_ADDRESS 1
#define NXT_AVR_N_OUTPUTS 4
#define NXT_AVR_N_INPUTS  4

// Link states
#define LS_CLOSED 0
#define LS_INIT1 1
#define LS_INIT2 2
#define LS_RUNNING 3
#define LS_RETRY 4
#define LS_RESET 5

// This string is used to establish communictions with the AVR
const char avr_brainwash_string[] =
  "\xCC" "Let's samba nxt arm in arm, (c)LEGO System A/S";
// The following Raw values are read/written directly to the AVR. so byte
// order, packing etc. must match
typedef struct{
  // Raw values
  U8 power;
  U8 pwm_frequency;
  S8 output_percent[NXT_AVR_N_OUTPUTS];
  U8 output_mode;
  U8 input_power;
} __attribute__((packed)) to_avr;
static to_avr io_to_avr;
// Output data is double buffered via the following (note extra space for csum
static U8 data_to_avr[5 + NXT_AVR_N_OUTPUTS];


typedef struct {
  // Raw values
  U16 adc_value[NXT_AVR_N_INPUTS];
  U16 buttonsVal;
  U16 extra;
  U8 csum;
} __attribute__((packed)) from_avr;
static from_avr data_from_avr[2], *io_from_avr;
// Input data is double buffered by buffer flipping
static U32 from_buf;
#define NEXT_BUF() ((from_buf + 1) & 0x1)

// 50ms Debounce time. Button read is called every other 1000Hz tick
#define BUTTON_DEBOUNCE_CNT 50/2;
static U16 prev_buttons;
static U16 button_state;
static U16 debounce_state;
static U16 debounce_cnt;



/**
 * Start to read the status data from the AVR. The actual I/O takes place
 * via DMA/Interrupt handling
 */
static void
nxt_avr_start_read(void)
{
  //memset(data_from_avr, 0, sizeof(data_from_avr));
  twi_start_read(NXT_AVR_ADDRESS, (U8 *)(&data_from_avr[from_buf]), sizeof(from_avr));
}

/**
 * Start to send command data to the AVR
 */
static void
nxt_avr_start_send(void)
{
  U32 checkByte = 0;
  U8 *a = data_to_avr;
  U8 *b = (U8 *) (&io_to_avr);
  U8 *e = b + sizeof(io_to_avr);

  // Copy over the data and create the checksum
  while (b < e) {
    checkByte += *b;
    *a++ = *b++;
  }

  *a = ~checkByte;

  twi_start_write(NXT_AVR_ADDRESS, data_to_avr, sizeof(data_to_avr));

}

/**
 * Tell the AVR to power down the NXT
 */
void
nxt_avr_power_down(void)
{
  io_to_avr.power = 0x5a;
  io_to_avr.pwm_frequency = 0x00;
}


/**
 * Tell the AVR to enter SAMBA mode
 */
void
nxt_avr_firmware_update_mode(void)
{
  io_to_avr.power = 0xA5;
  io_to_avr.pwm_frequency = 0x5A;
}

/**
 * Initialise the link with the AVR by sending the handshake string. Note that
 * because of the length of this string we need to allow more than 1ms for it
 * to go.
 */
void
nxt_avr_link_init(void)
{
  twi_start_write(NXT_AVR_ADDRESS, (const U8 *) avr_brainwash_string,
		  strlen(avr_brainwash_string));
}


static struct {
  U32 good_rx;
  U32 bad_rx;
  U32 resets;
  U32 still_busy;
  U32 not_ok;
} nxt_avr_stats;

/**
 * Unpack the status data from the AVR. Also need to check the checksum byte
 * is ok.
 */
static void
nxt_avr_unpack(void)
{
  U8 check_sum=0;;
  U8 *p;
  U8 *end;
  U16 buttonsVal;
  U16 newState;

  // calc the checksum
  p = (U8 *) (&data_from_avr[from_buf]);
  end = p + sizeof(from_avr);
  while(p < end) {
    check_sum += *p++;
  }
  if (check_sum != 0xff) {
    nxt_avr_stats.bad_rx++;
    return;
  }

  // Got good data
  nxt_avr_stats.good_rx++;
  // Flip the buffers
  io_from_avr = &data_from_avr[from_buf];
  from_buf = NEXT_BUF();
  buttonsVal = io_from_avr->buttonsVal;
  if (buttonsVal > 60 || button_state)
  {
    // Process the buttons. First we drop any noisy inputs
    if (buttonsVal != prev_buttons)
      prev_buttons = buttonsVal;
    else
    {
      // Work out which buttons are down. We allow chording of the enter
      // button with other buttons
      newState = 0;
      if (buttonsVal > 1500) {
        newState |= 1;
        buttonsVal -= 0x7ff;
      }
  
      if (buttonsVal > 720)
        newState |= 0x08;
      else if (buttonsVal > 270)
        newState |= 0x04;
      else if (buttonsVal > 60)
        newState |= 0x02;
      // Debounce things...
      if (newState != debounce_state)
      {
        debounce_cnt = BUTTON_DEBOUNCE_CNT;
        debounce_state = newState;
      }
      else if (debounce_cnt > 0)
        debounce_cnt--;
      else
        // Got a good key, make a note of it
        button_state = debounce_state;
    }
  }
}

static U32 update_count;
static U32 link_state = LS_CLOSED;

/**
 * Set things up ready to start talking to the AVR.
 */
void
nxt_avr_init(void)
{
  twi_init();

  memset(&io_to_avr, 0, sizeof(io_to_avr));
  io_to_avr.power = 0;
  io_to_avr.pwm_frequency = 8;
  button_state = 0;
  prev_buttons = 0;
  debounce_state = 0;
  debounce_cnt = BUTTON_DEBOUNCE_CNT;
  link_state = LS_RESET;
  from_buf = 0;
  io_from_avr = &data_from_avr[1];
}


/**
 * Main procssing function. Called from a low priority interrupt every 1ms.
 */
void
nxt_avr_1kHz_update(void)
{
  int state;
  switch(link_state)
  {
  case LS_CLOSED:
    break;

  case LS_INIT1:
  case LS_INIT2:
    // Add extra wait states during initialisation
    link_state++;
    break;

  case LS_RUNNING:
  case LS_RETRY:
    // Check to make sure the link is ok
    state = twi_status();
    if (state == 0) {
      // Everything looks good, so do the real work
      if (update_count++ & 1) {
        nxt_avr_start_read();
      } else {
        nxt_avr_start_send();
        nxt_avr_unpack();
      }
      link_state = LS_RUNNING;
    }
    else {
      if (state < 0) {
        nxt_avr_stats.not_ok++;
        link_state = LS_RESET;
      }
      else {
        nxt_avr_stats.still_busy++;
        // If the link is still busy (normally it should not be). We allow it
        // a little extra time to see if it will complete. If not then reset
        // it.
        if (link_state == LS_RUNNING)
          link_state = LS_RETRY;
        else
          link_state = LS_RESET;
      }
    }
    break;

  case LS_RESET:
  default:
    // Either we are just starting or we have had a problem. So reset the
    // hardware and try and re-establish the link.
    twi_init();
    memset(data_from_avr, 0, sizeof(data_from_avr));
    nxt_avr_link_init();
    update_count = 0;
    nxt_avr_stats.resets++;
    link_state = LS_INIT1;
    break;
  }
}
  
/**
 * Return a bitmask giving the current (debounced) button state
 */
U32
buttons_get(void)
{
  return button_state;
}

/**
 * Return the current state of the battery
 */
U32
battery_voltage(void)
{
  // Figure out voltage
  // The units are 13.848 mV per bit.
  // To prevent fp, we substitute 13.848 with 14180/1024
  U32 voltageVal = io_from_avr->extra;
  voltageVal &= 0x3ff;		// Toss unwanted bits.
  voltageVal *= 14180;
  voltageVal >>= 10;
  return voltageVal;
}

/**
 * Return the requests sensor analoge reading.
 */
U32
sensor_adc(U32 n)
{
  if (n < 4)
    return io_from_avr->adc_value[n];
  else
    return 0;
}


/**
 * Set the motor power for a particular motor
 */
void
nxt_avr_set_motor(U32 n, int power_percent, int brake)
{
  if (n < NXT_N_MOTORS) {
    io_to_avr.output_percent[n] = power_percent;
    if (brake)
      io_to_avr.output_mode |= (1 << n);
    else
      io_to_avr.output_mode &= ~(1 << n);
  }
}

/**
 * Control the power supplied to an input sensor
 */
void
nxt_avr_set_input_power(U32 n, U32 power_type)
{
  // The power to the sensor is controlled by a bit in
  // each of the two nibbles of the byte. There is one
  // bit for each of the four sensors. if the low nibble
  // bit is set then the sensor is "ACTIVE" and 9v is
  // supplied to it but it will be pulsed off to allow
  // the sensor to be be read. A 1 in the high nibble
  // indicates that it is a 9v always on sensor and
  // 9v will be supplied constantly. If both bits are
  // clear then 9v is not supplied to the sensor. 
  // Having both bits set is currently not supported.
  if (n < NXT_AVR_N_INPUTS && power_type <= 2) {
    U8 val = (power_type & 0x2 ? 0x10 << n : 0) | ((power_type & 1) << n);
    io_to_avr.input_power &= ~(0x11 << n);
    io_to_avr.input_power |= val;
  }
}

