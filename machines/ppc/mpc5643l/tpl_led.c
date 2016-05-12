#include "tpl_os_std_types.h"
#include "Compiler.h"

#define LED_COUNT  4

/*
 * LED0 => GPIO52
 * LED1 => GPIO53
 * LED2 => GPIO54
 * LED3 => GPIO55
 */
#define LED1    52
#define LED2    53
#define LED3    54
#define LED4    55

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
STATIC CONST(uint8, OS_CONST) led_tab[LED_COUNT] = {LED1, LED2, LED3, LED4};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*  System Integration Unit (SIU) section
 */
struct __siu__ {
    uint32 reserved_0;
    uint32 MIDR1;         /* MCU ID Register 1 */
    uint32 MIDR2;         /* MCU ID Register 2 */
    uint32 reserved_1[2];
    uint32 ISR;           /* Interrupt Status Register */
    uint32 IRER;          /* Interrupt Request Enable Register */
    uint32 reserved_2[3];
    uint32 IREER;         /* Interrupt Rising-Edge Event Enable Register */
    uint32 IFEER;         /* Interrupt Falling-Edge Event Enable Register */
    uint32 IFER;          /* Interrupt Filter Enable Register */
    uint32 reserved_3[3];
    uint16 PCR[108];      /* Pad Configuration Registers */
    uint32 reserved_4[250];
    uint8  PSMI[36];      /* Pad Selection for Multiplexed Input */
    uint32 reserved_5[55];
    uint8  GPDO[108];     /* GPIO Pin Data Output Registers */
    uint32 reserved_6[101];
    uint8  GPDI[108];     /* GPIO Pin Data Input Registers */
    uint32 reserved_7[229];
    uint32 PGPDO[4];      /* Parallel GPIO Pin Data Output Registers */
    uint32 reserved_8[12];
    uint32 PGPDI[4];      /* Parallel GPIO Pin Data Input Registers */
    uint32 reserved_9[12];
    uint32 MPGPDO[4];     /* Masked Parallel GPIO Pin Data Output */
    uint32 reserved_10[217];
    uint32 IFMC[32];      /* Interrupt Filter Maximum Counter Register */
    uint32 IFCPR;         /* Interrupt Filter Clock Prescaler Register */
    };

#define SIU (* (volatile struct __siu__*) 0xC3F90000UL)

void initLed()
{
    int i;
    for(i = 0; i < LED_COUNT; i++)
    {
        int led_id = led_tab[i];
        SIU.PCR[led_id] = 0x204;  // set outputs
        SIU.GPDO[led_id] = 1;     // Light off
    }
}


void setLed(unsigned int id, unsigned int state)
{
    int led_id = led_tab[id % LED_COUNT];
    SIU.GPDO[led_id] = state ? 0 : 1;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

