#ifndef __PINMUX_H__
#define __PINMUX_H__


#define CONFIG_A 0
#define CONFIG_B 1
#define CONFIG_C 2
#define CONFIG_D 3
#define CONFIG_E 4
#define CONFIG_F 5
#define CONFIG_G 6
#define CONFIG_H 7

//configuration d'une broche pour un peripherique (autre que I/O).
//exemple: broche PA.14 utilisée pour le timer TC3 (WO0)
//         -> configuration E d'après datasheet (p.15)
//         -> configBroche(PORTA,15,CONFIG_E);
void pinMux(unsigned char port,unsigned char numBit, unsigned char config);

#endif
