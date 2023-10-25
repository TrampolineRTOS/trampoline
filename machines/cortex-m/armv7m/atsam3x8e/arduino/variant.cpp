/*
  Copyright (c) 2011 Arduino LLC.  All right reserved.
  Copyright (c) 2015 Thibaut VIARD.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

/*
 * DUE Board pin   |  PORT  | Label
 * ----------------+--------+-------
 *  74       MISO  |  PA25  |
 *  75       MOSI  |  PA26  |
 *  76       SCLK  |  PA27  |
 *  77       NPCS0 |  PA28  |
 *  78       NPCS3 |  PB23  | unconnected!
 *
 * USB pin         |  PORT
 * ----------------+--------
 *  ID             |  PB11
 *  VBOF           |  PB10
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

const Port Ports[NUM_PORTS]=
{
  { .pGPIO=PIOA, .ulId=ID_PIOA },
  { .pGPIO=PIOB, .ulId=ID_PIOB },
  { .pGPIO=PIOC, .ulId=ID_PIOC },
  { .pGPIO=PIOD, .ulId=ID_PIOD }
};

/*
 * Pins descriptions
 */
const PinDescription g_aPinMap[]=
{
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          |                  |  PA8   | RX0             | URXD
 * | 1          |                  |  PA9   | TX0             | UTXD
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 *   2       TIOA0 |  PB25  |
 *   3       TIOA7 |  PC28  |
 *   4       NPCS1 |  PA29  |
 *           TIOB6 |  PC26  |
 *   5       TIOA6 |  PC25  |
 *   6       PWML7 |  PC24  |
 *   7       PWML6 |  PC23  |
 *   8       PWML5 |  PC22  |
 *   9       PWML4 |  PC21  |
 *  10       NPCS0 |  PA28  |
 *           TIOB7 |  PC29  |
 *  11       TIOA8 |  PD7   |
 *  12       TIOB8 |  PD8   |
 *  13       TIOB0 |  PB27  | LED AMBER "L"
 *  14       TXD3  |  PD4   | "TX3"
 *  15       RXD3  |  PD5   | "RX3"
 *  16       TXD1  |  PA13  | "TX2"
 *  17       RXD1  |  PA12  | "RX2"
 *  18       TXD0  |  PA11  | "TX1"
 *  19       RXD0  |  PA10  | "RX1"
 *  20             |  PB12  | "SDA"
 *  21             |  PB13  | "SCL"
 *  22             |  PB26  |
 *  23             |  PA14  |
 *  24             |  PA15  |
 *  25             |  PD0   |
 *  26             |  PD1   |
 *  27             |  PD2   |
 *  28             |  PD3   |
 *  29             |  PD6   |
 *  30             |  PD9   |
 *  31             |  PA7   |
 *  32             |  PD10  |
 *  33             |  PC1   |
 *  34             |  PC2   |
 *  35             |  PC3   |
 *  36             |  PC4   |
 *  37             |  PC5   |
 *  38             |  PC6   |
 *  39             |  PC7   |
 *  40             |  PC8   |
 *  41             |  PC9   |
 *  42             |  PA19  |
 *  43             |  PA20  |
 *  44             |  PC19  |
 *  45             |  PC18  |
 *  46             |  PC17  |
 *  47             |  PC16  |
 *  48             |  PC15  |
 *  49             |  PC14  |
 *  50             |  PC13  |
 *  51             |  PC12  |
 *  52       NPCS2 |  PB21  |
 *  53             |  PB14  |
*/
  // 0 .. 53 - Digital pins
  // ----------------------
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          |                  |  PA8   | RX0             | URXD
 * | 1          |                  |  PA9   | TX0             | UTXD
 * |            |                  |  xxx   | xxx             |
 * |            |                  |  xxx   | xxx             |
 * |            |                  |  xxx   | xxx             |
 * |            |                  |  xxx   | xxx             |
 * |            |                  |  xxx   | xxx             |
 * |            |                  |  xxx   | xxx             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  // 0/1 - UART (Serial)
  { PORTA, PIO_PA8A_URXD, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // URXD
  { PORTA, PIO_PA9A_UTXD, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // UTXD

  // 2
  { PORTB, PIO_PB25B_TIOA0, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC0_CHA0 }, // TIOA0
  { PORTC, PIO_PC28B_TIOA7, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC2_CHA7 }, // TIOA7
  { PORTC, PIO_PC26B_TIOB6, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC2_CHB6 }, // TIOB6

  // 5
  { PORTC, PIO_PC25B_TIOA6, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC2_CHA6 }, // TIOA6
  { PORTC, PIO_PC24B_PWML7, GPIO_PERIPH_B, NOT_ON_ANALOG, PWM_CHL7, NOT_ON_TIMER }, // PWML7
  { PORTC, PIO_PC23B_PWML6, GPIO_PERIPH_B, NOT_ON_ANALOG, PWM_CHL6, NOT_ON_TIMER }, // PWML6

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital high     |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 8          |                  |  xxx   | xxx             |
 * | 9          |                  |  xxx   | xxx             |
 * | 10         |                  |  xxx   | xxx             |
 * | 11         |                  |  xxx   | xxx             |
 * | 12         |                  |  xxx   | xxx             |
 * | 13         |                  |  xxx   | xxx             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTC, PIO_PC22B_PWML5, GPIO_PERIPH_B, NOT_ON_ANALOG, PWM_CHL5, NOT_ON_TIMER }, // PWML5
  { PORTC, PIO_PC21B_PWML4, GPIO_PERIPH_B, NOT_ON_ANALOG, PWM_CHL4, NOT_ON_TIMER }, // PWML4
  // 10
  { PORTC, PIO_PC29B_TIOB7, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC2_CHB7 }, // TIOB7
  { PORTD, PIO_PD7B_TIOA8, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC2_CHA8 }, // TIOA8
  { PORTD, PIO_PD8B_TIOB8, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC2_CHB8 }, // TIOB8

  // 13 - AMBER LED
  { PORTB, PIO_PB27B_TIOB0, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, TC0_CHB0 }, // TIOB0

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital comm.    |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 14         |                  |  xxx   | TX3             | TXD3
 * | 15         |                  |  xxx   | RX3             | RXD3
 * | 16         |                  |  xxx   | TX2             | TXD1
 * | 17         |                  |  xxx   | RX2             | RXD1
 * | 18         |                  |  xxx   | TX1             | TXD0
 * | 19         |                  |  xxx   | RX1             | RXD0
 * | 20         |                  |  xxx   | SDA             | SDA0
 * | 21         |                  |  xxx   | SCL             | SCL0
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  // 14/15 - USART3 (Serial3)
  { PORTD, PIO_PD4B_TXD3, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // TXD3
  { PORTD, PIO_PD5B_RXD3, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // RXD3

  // 16/17 - USART1 (Serial2)
  { PORTA, PIO_PA13A_TXD1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // TXD1
  { PORTA, PIO_PA12A_RXD1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // RXD1

  // 18/19 - USART0 (Serial1)
  { PORTA, PIO_PA11A_TXD0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // TXD0
  { PORTA, PIO_PA10A_RXD0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // RXD0

  // 20/21 - TWI1
  { PORTB, PIO_PB12A_TWD1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // TWD1 - SDA0
  { PORTB, PIO_PB13A_TWCK1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // TWCK1 - SCL0

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital          |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 22         |                  |  xxx   | xxx             |
 * | 23         |                  |  xxx   | xxx             |
 * | 24         |                  |  xxx   | xxx             |
 * | 25         |                  |  xxx   | xxx             |
 * | 26         |                  |  xxx   | xxx             |
 * | 27         |                  |  xxx   | xxx             |
 * | 28         |                  |  xxx   | xxx             |
 * | 29         |                  |  xxx   | xxx             |
 * | 30         |                  |  xxx   | xxx             |
 * | 31         |                  |  xxx   | xxx             |
 * | 32         |                  |  xxx   | xxx             |
 * | 33         |                  |  xxx   | xxx             |
 * | 34         |                  |  xxx   | xxx             |
 * | 35         |                  |  xxx   | xxx             |
 * | 36         |                  |  xxx   | xxx             |
 * | 37         |                  |  xxx   | xxx             |
 * | 38         |                  |  xxx   | xxx             |
 * | 39         |                  |  xxx   | xxx             |
 * | 40         |                  |  xxx   | xxx             |
 * | 41         |                  |  xxx   | xxx             |
 * | 42         |                  |  xxx   | xxx             |
 * | 43         |                  |  xxx   | xxx             |
 * | 44         |                  |  xxx   | xxx             |
 * | 45         |                  |  xxx   | xxx             |
 * | 46         |                  |  xxx   | xxx             |
 * | 47         |                  |  xxx   | xxx             |
 * | 48         |                  |  xxx   | xxx             |
 * | 49         |                  |  xxx   | xxx             |
 * | 50         |                  |  xxx   | xxx             |
 * | 51         |                  |  xxx   | xxx             |
 * | 52         |                  |  xxx   | xxx             |
 * | 53         |                  |  xxx   | xxx             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  // 22
  { PORTB, PIO_PB26, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 22
  { PORTA, PIO_PA14, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 23
  { PORTA, PIO_PA15, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 24
  { PORTD, PIO_PD0, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 25

  // 26
  { PORTD, PIO_PD1, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 26
  { PORTD, PIO_PD2, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 27
  { PORTD, PIO_PD3, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 28
  { PORTD, PIO_PD6, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 29

  // 30
  { PORTD, PIO_PD9, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 30
  { PORTA, PIO_PA7, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 31
  { PORTD, PIO_PD10, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 32
  { PORTC, PIO_PC1, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 33

  // 34
  { PORTC, PIO_PC2, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 34
  { PORTC, PIO_PC3, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 35
  { PORTC, PIO_PC4, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 36
  { PORTC, PIO_PC5, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 37

  // 38
  { PORTC, PIO_PC6, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 38
  { PORTC, PIO_PC7, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 39
  { PORTC, PIO_PC8, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 40
  { PORTC, PIO_PC9, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 41

  // 42
  { PORTA, PIO_PA19, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 42
  { PORTA, PIO_PA20, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 43
  { PORTC, PIO_PC19, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 44
  { PORTC, PIO_PC18, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 45

  // 46
  { PORTC, PIO_PC17, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 46
  { PORTC, PIO_PC16, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 47
  { PORTC, PIO_PC15, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 48
  { PORTC, PIO_PC14, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 49

  // 50
  { PORTC, PIO_PC13, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 50
  { PORTC, PIO_PC12, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 51
  { PORTB, PIO_PB21, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 52
  { PORTB, PIO_PB14, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // PIN 53

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Analog input     |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 54         |                  |  PA16  | A0              |
 * | 55         |                  |  PA24  | A1              |
 * | 56         |                  |  PA23  | A2              |
 * | 57         |                  |  PA22  | A3              |
 * | 58         |                  |  PA6   | A4              | TIOB2
 * | 69         |                  |  PA4   | A5              |
 * | 60         |                  |  PA3   | A6              | TIOB1
 * | 61         |                  |  PA2   | A7              | TIOA1
 * | 62         |                  |  PB17  | A8              |
 * | 63         |                  |  PB18  | A9              |
 * | 64         |                  |  PB19  | A10             |
 * | 65         |                  |  PB20  | A11             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  // 54 .. 65 - Analog pins
  // ----------------------
  { PORTA, PIO_PA16X1_AD7, GPIO_NOMUX, ADC_CHL7, NOT_ON_PWM, NOT_ON_TIMER }, // AD7
  { PORTA, PIO_PA24X1_AD6, GPIO_NOMUX, ADC_CHL6, NOT_ON_PWM, NOT_ON_TIMER }, // AD6
  { PORTA, PIO_PA23X1_AD5, GPIO_NOMUX, ADC_CHL5, NOT_ON_PWM, NOT_ON_TIMER }, // AD5
  { PORTA, PIO_PA22X1_AD4, GPIO_NOMUX, ADC_CHL4, NOT_ON_PWM, NOT_ON_TIMER }, // AD4
  // 58
  { PORTA, PIO_PA6X1_AD3, GPIO_NOMUX, ADC_CHL3, NOT_ON_PWM, TC0_CHB2 }, // AD3
  { PORTA, PIO_PA4X1_AD2, GPIO_NOMUX, ADC_CHL2, NOT_ON_PWM, NOT_ON_TIMER }, // AD2
  { PORTA, PIO_PA3X1_AD1, GPIO_NOMUX, ADC_CHL1, NOT_ON_PWM, TC0_CHB1 }, // AD1
  { PORTA, PIO_PA2X1_AD0, GPIO_NOMUX, ADC_CHL0, NOT_ON_PWM, TC0_CHA1 }, // AD0
  // 62
  { PORTB, PIO_PB17X1_AD10, GPIO_NOMUX, ADC_CHL10, NOT_ON_PWM, NOT_ON_TIMER }, // AD10
  { PORTB, PIO_PB18X1_AD11, GPIO_NOMUX, ADC_CHL11, NOT_ON_PWM, NOT_ON_TIMER }, // AD11
  { PORTB, PIO_PB19X1_AD12, GPIO_NOMUX, ADC_CHL12, NOT_ON_PWM, NOT_ON_TIMER }, // AD12
  { PORTB, PIO_PB20X1_AD13, GPIO_NOMUX, ADC_CHL13, NOT_ON_PWM, NOT_ON_TIMER }, // AD13

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Analog output    |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 66         |                  |  PB15  | DAC0            |
 * | 67         |                  |  PB16  | DAC1            |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTB, PIO_PB15X1_DAC0, GPIO_NOMUX, DAC_CHL0, NOT_ON_PWM, NOT_ON_TIMER }, // DAC0
  { PORTB, PIO_PB16X1_DAC1, GPIO_NOMUX, DAC_CHL1, NOT_ON_PWM, NOT_ON_TIMER }, // DAC1

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | CAN              |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 68         |                  |  PA1   | CANRX           |
 * | 69         |                  |  PA0   | CANTX           |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, PIO_PA1A_CANRX0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // CANRX
  { PORTA, PIO_PA0A_CANTX0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // CANTX

  // 70/71 - TWI0
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Wire             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 70         |                  |  PA17  | SDA1            |
 * | 71         |                  |  PA18  | SCL1            |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTA, PIO_PA17A_TWD0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // TWD0 - SDA1
  { PORTA, PIO_PA18A_TWCK0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // TWCK0 - SCL1

  // 72/73 - LEDs
/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | RX/TX leds       |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 72         |                  |  PC30  | RX              |
 * | 73         |                  |  PA21  | TX              |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  { PORTC, PIO_PC30, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // LED AMBER RXL
  { PORTA, PIO_PA21, GPIO_NOMUX, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // LED AMBER TXL

/* +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | SPI              |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 74         |                  |  xxx   | xxx             |
 * | 74         |                  |  xxx   | xxx             |
 * | 74         |                  |  xxx   | xxx             |
 * | 74         |                  |  xxx   | xxx             |
 * | 74         |                  |  xxx   | xxx             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
  // 74/75/76 - SPI
  { PORTA, PIO_PA25A_SPI0_MISO, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // MISO
  { PORTA, PIO_PA26A_SPI0_MOSI, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // MOSI
  { PORTA, PIO_PA27A_SPI0_SPCK, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // SPCK

  // 77 - SPI CS0
  { PORTA, PIO_PA28A_SPI0_NPCS0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // NPCS0

  // 78 - SPI CS3 (unconnected)
  { PORTB, PIO_PB23B_SPI0_NPCS3, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // NPCS3

  // 79 .. 84 - "All pins" masks

  // 79 - TWI0 all pins
  { PORTA, PIO_PA17A_TWD0|PIO_PA18A_TWCK0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER },
  // 80 - TWI1 all pins
  { PORTB, PIO_PB12A_TWD1|PIO_PB13A_TWCK1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER },
  // 81 - UART (Serial) all pins
  { PORTA, PIO_PA8A_URXD|PIO_PA9A_UTXD, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER },
  // 82 - USART0 (Serial1) all pins
  { PORTA, PIO_PA11A_TXD0|PIO_PA10A_RXD0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER },
  // 83 - USART1 (Serial2) all pins
  { PORTA, PIO_PA13A_TXD1|PIO_PA12A_RXD1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER },
  // 84 - USART3 (Serial3) all pins
  { PORTD, PIO_PD4B_TXD3|PIO_PD5B_RXD3, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER },

  // 85 - USB
  { PORTB, PIO_PB11A_UOTGID|PIO_PB10A_UOTGVBOF, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // ID - VBOF

  // 86 - SPI CS2
  { PORTB, PIO_PB21B_SPI0_NPCS2, GPIO_PERIPH_B, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // NPCS2

  // 87 - SPI CS1
  { PORTA, PIO_PA29A_SPI0_NPCS1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // NPCS1

  // 88/89 - CANRX1/CANTX1 (same physical pin for 66/53)
  { PORTB, PIO_PB15A_CANRX1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // CANRX1
  { PORTB, PIO_PB14A_CANTX1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }, // CANTX1

  // 90 .. 91 - "All CAN pins" masks
  // 90 - CAN0 all pins
  { PORTA, PIO_PA1A_CANRX0|PIO_PA0A_CANTX0, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER },
  // 91 - CAN1 all pins
  { PORTB, PIO_PB15A_CANRX1|PIO_PB14A_CANTX1, GPIO_PERIPH_A, NOT_ON_ANALOG, NOT_ON_PWM, NOT_ON_TIMER }
};

#ifdef __cplusplus
}
#endif

/*
 * Serialx objects
 */
// Serial Interrupt handler
static void Serial_Handler(void)
{
  Serial.IrqHandler();
}

SAMSerial Serial((Usart*)UART0, PIN_SERIAL_RX, PIN_SERIAL_TX, Serial_Handler, 1);
void serialEvent() __attribute__((weak));
void serialEvent() { }

// Serial1 Interrupt handler
static void Serial1_Handler(void)
{
  Serial1.IrqHandler();
}

SAMSerial Serial1(USART0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, Serial1_Handler, 0);
void serialEvent1() __attribute__((weak));
void serialEvent1() { }

// Serial2 Interrupt handler
static void Serial2_Handler(void)
{
  Serial2.IrqHandler();
}

SAMSerial Serial2(USART1, PIN_SERIAL2_RX, PIN_SERIAL2_TX, Serial2_Handler, 0);
void serialEvent2() __attribute__((weak));
void serialEvent2() { }

// Serial3 Interrupt handler
static void Serial3_Handler(void)
{
  Serial3.IrqHandler();
}

SAMSerial Serial3(USART3, PIN_SERIAL3_RX, PIN_SERIAL3_TX, Serial3_Handler, 0);
void serialEvent3() __attribute__((weak));
void serialEvent3() { }

// ----------------------------------------------------------------------------

void serialEventRun(void)
{
  if (Serial.available()) serialEvent();
  if (Serial1.available()) serialEvent1();
  if (Serial2.available()) serialEvent2();
  if (Serial3.available()) serialEvent3();
}

// ----------------------------------------------------------------------------

/*
 * Wirex objects
 */

static void Wire_Handler(void)
{
  Wire.onService();
}

TwoWire Wire(WIRE_INTERFACE, PIN_WIRE_SDA, PIN_WIRE_SCL, Wire_Handler);

// ----------------------------------------------------------------------------

static void Wire1_Handler(void)
{
  Wire1.onService();
}

TwoWire Wire1(WIRE1_INTERFACE, PIN_WIRE1_SDA, PIN_WIRE1_SCL, Wire1_Handler);

// ----------------------------------------------------------------------------
