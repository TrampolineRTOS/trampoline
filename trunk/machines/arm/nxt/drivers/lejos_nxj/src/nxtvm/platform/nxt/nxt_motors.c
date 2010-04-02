#include "nxt_motors.h"

#include "nxt_avr.h"
#include "aic.h"
#include "interrupts.h"

#include "AT91SAM7.h"

#define MA0 15
#define MA1 1
#define MB0 26
#define MB1 9
#define MC0 0
#define MC1 8

#define MOTOR_PIN_MASK 		((1 << MA0) | (1<<MA1) | (1<<MB0) | (1<<MB1) | (1<<MC0) | (1<<MC1))
#define MOTOR_INTERRUPT_PINS 	((1 << MA0) | (1<<MB0) | (1<<MC0))


static struct motor_struct {
  int current_count;
  int target_count;
  int speed_percent;
  U32 last;
} motor[NXT_N_MOTORS];

static U32 nxt_motor_initialised;
static U32 interrupts_this_period;

int
nxt_motor_get_count(U32 n)
{
  if (n < NXT_N_MOTORS)
    return motor[n].current_count;
  else
    return 0;
}

void
nxt_motor_set_count(U32 n, int count)
{
  if (n < NXT_N_MOTORS)
    motor[n].current_count = count;
}

void
nxt_motor_set_speed(U32 n, int speed_percent, int brake)
{
  if (n < NXT_N_MOTORS) {
    if (speed_percent > 100)
      speed_percent = 100;
    if (speed_percent < -100)
      speed_percent = -100;
    motor[n].speed_percent = speed_percent;
    nxt_avr_set_motor(n, speed_percent, brake);
  }
}

void
nxt_motor_command(U32 n, int cmd, int target_count, int speed_percent)
{
  if (n < NXT_N_MOTORS) {
    motor[n].target_count = target_count;
    motor[n].speed_percent = speed_percent;
  }
}


void
nxt_motor_1kHz_process(void)
{
  if (nxt_motor_initialised) {
    interrupts_this_period = 0;
    *AT91C_PIOA_IER = MOTOR_INTERRUPT_PINS;
  }

}

void
nxt_motor_quad_decode(struct motor_struct *m, U32 value)
{
#if 0
  if (m->last != value) {
    if ((m->last + 1) & 3 == value)
      m->current_count--;
    else if ((value + 1) & 3 == m->last)
      m->current_count++;
    m->last = value;
  }
#endif

  U32 dir = value & 2;
  U32 edge = value & 1;

  if (edge != m->last) {
    if (edge && !dir)
      m->current_count++;
    else if (edge && dir)
      m->current_count--;
    else if (!edge && dir)
      m->current_count++;
    else if (!edge && !dir)
      m->current_count--;
    m->last = edge;
  }
}


extern void nxt_motor_isr_entry(void);

void nxt_motor_isr_C_function(void)
{
  U32 i_state = interrupts_get_and_disable();

  U32 pinChanges = *AT91C_PIOA_ISR;	// Acknowledge change
  U32 currentPins = *AT91C_PIOA_PDSR;	// Read pins

  U32 pins;

  interrupts_this_period++;
  if (interrupts_this_period > 4) {
    *AT91C_PIOA_IDR = MOTOR_INTERRUPT_PINS;
    // Todo : tacho speed fault
  }


  /* Motor A */
  pins = ((currentPins >> MA0) & 1) | ((currentPins >> (MA1 - 1)) & 2);
  nxt_motor_quad_decode(&motor[0], pins);

  /* Motor B */
  pins = ((currentPins >> MB0) & 1) | ((currentPins >> (MB1 - 1)) & 2);
  nxt_motor_quad_decode(&motor[1], pins);

  /* Motor C */
  pins = ((currentPins >> MC0) & 1) | ((currentPins >> (MC1 - 1)) & 2);
  nxt_motor_quad_decode(&motor[2], pins);

  if (i_state)
    interrupts_enable();

}

extern void tpl_primary_irq_handler(void);

void
nxt_motor_init(void)
{
  *AT91C_PMC_PCER = (1 << AT91C_PERIPHERAL_ID_PIOA);	/* Power to the pins! */
  *AT91C_PIOA_IDR = ~0;
  *AT91C_PIOA_IFER = MOTOR_PIN_MASK;
  *AT91C_PIOA_PPUDR = MOTOR_PIN_MASK;
  *AT91C_PIOA_PER = MOTOR_PIN_MASK;
  *AT91C_PIOA_ODR = MOTOR_PIN_MASK;

  /* Enable ISR */
  aic_mask_off(AT91C_PERIPHERAL_ID_PIOA);
  aic_set_vector(AT91C_PERIPHERAL_ID_PIOA, AIC_INT_LEVEL_NORMAL,
		  (U32) tpl_primary_irq_handler);//(U32) nxt_motor_isr_entry);
  aic_mask_on(AT91C_PERIPHERAL_ID_PIOA);

  *AT91C_PIOA_IER = MOTOR_INTERRUPT_PINS;

  nxt_motor_initialised = 1;


}
