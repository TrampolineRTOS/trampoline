#include "rpi2_misc.h"

void disable_gppud() {
	unsigned int register_a;
	/* Control signal: Disable pull-up/pull-down on GPIO pin
   * determined by GPPUDCLK
   */
	write_to_address(GPPUD,0);
	/* Delay for at least 150 CPU cycles (set-up time of control signal). */
	for(register_a = 0; register_a < 150; register_a++){
		delay();
	}
	/* Writing a "1" to a bit in GPPUDCLK0 or GPPUDCLK1 allows us to select
   * that bit (bits in GPPUDCLK1 are transposed by 32) for control.
   * JTAG: 4 (Alt5: ARM_TDI), 22 (Alt4: ARM_TRST), 24 (Alt4: ARM_TDO),
   *       25 (Alt4: ARM_TCK), 27 (Alt4: ARM_TMS)
	 * UART: 14 (Alt1: TXD0), 15 (Alt1: RXD0)
	 * LED:  47 (Alt1: OK LED)
   */
	write_to_address(GPPUDCLK0,(1<<4)|(1<<14)|(1<<15)|(1<<22)|(1<<24)|(1<<25)|(1<<27));
	write_to_address(GPPUDCLK1,(1<<15));
	/* Delay for at least 150 CPU cycles (holding time of control signal). */
	for(register_a = 0; register_a < 150; register_a++){
		delay();
	}
	/* Remove the clock and control signal */
	/* write_to_address(GPPUD,0); */
	write_to_address(GPPUDCLK0,0);
	/* write_to_address(GPPUDCLK1,0); */
}

void jtag_init() {
	unsigned int register_a;

	/* Set GPIO4 to alternative function 5 by writing to register at GPFSEL0 */
	register_a = read_from_address(GPFSEL0);
	register_a &= ~(7<<12); /*gpio4 */
	register_a |= 2<<12; /*gpio4 alt5 ARM_TDI */
	write_to_address(GPFSEL0, register_a);

	/* Set other GPIOs to alternative functions by writing at GPFSEL2 */
	register_a = read_from_address(GPFSEL2);
	register_a &= ~(7<<6);  /* gpio22 */
	register_a |= 3<<6;     /* alt4 ARM_TRST */
	register_a &= ~(7<<12); /* gpio24 */
	register_a |= 3<<12;    /* alt4 ARM_TDO */
	register_a &= ~(7<<15); /* gpio25 */
	register_a |= 3<<15;    /* alt4 ARM_TCK */
	register_a &= ~(7<<21); /* gpio27 */
	register_a |= 3<<21;    /* alt4 ARM_TMS */
	write_to_address(GPFSEL2, register_a);
}

void timer_init() {
	write_to_address(ARM_TIMER_CTL, 0x00F90000);
	write_to_address(ARM_TIMER_CTL, 0x00F90200);
}

void led_init() {
	unsigned int register_a;
	register_a = read_from_address(LED_GPFSEL);
	register_a |= (1 << 21);
	write_to_address(LED_GPFSEL, register_a);
}
