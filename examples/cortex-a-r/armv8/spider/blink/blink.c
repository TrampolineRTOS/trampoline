#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
#include "stdint.h"
#include "stdbool.h"
uint8_t *led8 = (uint8_t*)(0xe6050180 + 0x14);

#define GPIO0_BASE_ADDR 0xe6050180
#define IOINTSEL 0x00   /* General IO/Interrupt Switching Register */
#define INOUTSEL 0x04   /* General Input/Output Switching Register */
#define OUTDT    0x08   /* General Output Register */
#define INDT     0x0c   /* General Input Register */
#define INTDT    0x10   /* Interrupt Display Register */
#define INTCLR   0x14   /* Interrupt Clear Register */
#define INTMSK   0x18   /* Interrupt Mask Register */
#define MSKCLR   0x1c   /* Interrupt Mask Clear Register */
#define POSNEG   0x20   /* Positive/Negative Logic Select Register */
#define EDGLEVEL 0x24   /* Edge/level Select Register */
#define FILONOFF 0x28   /* Chattering Prevention On/Off Register */
#define OUTDTSEL 0x40   /* Output Data Select Register */
#define BOTHEDGE 0x4c   /* One Edge/Both Edge Select Register */
#define INEN     0x50   /* General Input Enable Register */

#define GPIO_PIN 14

void gpio_modify_bit(uint32_t *addr, int bit, bool val) {
    uint32_t tmp = *addr;
    if(val) {
        tmp |= (1<<bit);
    } else {
        tmp &= ~(1<<bit);
    }
    *addr = tmp;
}

void init_gpio(void){
    uint32_t *addr;
    /** GPIO **/
    // *POSNEG = 0; // Positive logic
    addr = (uint32_t*)(GPIO0_BASE_ADDR+POSNEG);
    gpio_modify_bit(addr, GPIO_PIN, false);
    // *INEN = 0; // General input disable
    addr = (uint32_t*)(GPIO0_BASE_ADDR+INEN);
    gpio_modify_bit(addr, GPIO_PIN, false);
    // *IOINTSEL = 0; // General I/O mode
    addr = (uint32_t*)(GPIO0_BASE_ADDR+IOINTSEL);
    gpio_modify_bit(addr, GPIO_PIN, false);
    // *INOUTSEL = 1; // General Output mode
    addr = (uint32_t*)(GPIO0_BASE_ADDR+INOUTSEL);
    gpio_modify_bit(addr, GPIO_PIN, true);
    // *OUTDT    = led_status; // output
    addr = (uint32_t*)(GPIO0_BASE_ADDR+OUTDTSEL);
    gpio_modify_bit(addr, GPIO_PIN, false);

}

void led(uint8_t status) {
    uint32_t *addr;
    // *OUTDT    = led_status; // output
    addr = (uint32_t*)(GPIO0_BASE_ADDR+OUTDT);
    gpio_modify_bit(addr, GPIO_PIN, status);
}

volatile uint32_t temp = 0;
FUNC(int, OS_APPL_CODE) main(void)
{
	init_gpio();
        // for( int i = 0; i< 10; ++i) {
        //     led(0);
        //     for (int n=0; n<0xffffff; ++n) temp = n;
        //     led(1);
        //     for (int n=0; n<0xffffff; ++n) temp = n;
        // }
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

volatile uint32_t tmp = 0;
TASK(my_only_task)
{
	TerminateTask();
}

TASK(blink)
{
        static int8_t led_status = 0;
        led(led_status);
        led_status = 1 - led_status;
	TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
