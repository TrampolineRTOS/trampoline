#include <C167CS.H>
#include "gpio.h"

#define MAXOF(X) ((1 << (sizeof(X) << 3))-1)

unsigned int valmoteur=2000;
char moteur_onoff=0xFF;
unsigned long nbtours=0;

/*Fonction appellée lors d’un changement d’état du switch 1 */
void IntCC0(void) interrupt 0x10 {
	SetLED(1,!SW1);
}
/*Fonction appellée lors d’un changement d’état du switch 2 */
void IntCC1(void) interrupt 0x11 {
	SetLED(2,!SW2);
}
/*Fonction appellée lors d’un changement d’état du switch 3 */
void IntCC2(void) interrupt 0x12 {
	SetLED(3,!SW3);
}
/*Fonction appellée lors d’un changement d’état du switch 4 */
void IntCC3(void) interrupt 0x13 {
	SetLED(4,!SW4);
}
/*Fonction appellée lors d’un changement d’état du switch 5*/
void IntCC4(void) interrupt 0x14 {
	SetLED(5,!SW5);
}
/*Fonction appellée lors d’un changement d’état du switch 6 */
void IntCC5(void) interrupt 0x15 {
	SetLED(6,!SW6);
}
/*Fonction appellée lors d’un changement d’état du switch 7 */
void IntCC6(void) interrupt 0x16 {
	SetLED(7,!SW7);
}
/*Fonction appellée lors d’un changement d’état du switch 8 */
void IntCC7(void) interrupt 0x17 {
	SetLED(8,!SW8);
}

/*Fonction appelée lors d’un appui sur key 1 */
void IntCC8(void) interrupt 0x18 {
	unsigned char vpot1;
	vpot1 = GetVPot(1);
	BarGraphLED(vpot1,MAXOF(unsigned char));
}
/*Fonction appelée lors d’un appui sur key 2 */
void IntCC9(void) interrupt 0x19 {
	unsigned char vpot2;
	vpot2 = GetVPot(2);
	BarGraphLED(vpot2,MAXOF(unsigned char));
}
/*Fonction appelée lors d’un appui sur key 3 */
void IntCC10(void) interrupt 0x1A {
	unsigned char vpot3;
	vpot3 = GetVPot(3);
	BarGraphLED(vpot3,MAXOF(unsigned char));
}
/*Fonction appelée lors d’un appui sur key 4 */
void IntCC11(void) interrupt 0x1B {
	if (valmoteur <= 19900){
		valmoteur += 300;
		CMDMoteur(ON,1,valmoteur);
	}
}
/* Fonction appelée lors d’un appui sur key 5 */
void IntCC12(void) interrupt 0x1C {
	if (valmoteur >= 100){
		valmoteur -= 300;
		CMDMoteur(ON,1,valmoteur);
	}
}
/* Fonction appelée lors d’un appui sur key 6 */
void IntCC13(void) interrupt 0x1D {
	CMDMoteur(moteur_onoff,1,valmoteur);
	moteur_onoff = ~moteur_onoff;
}
/* Fonction à chaque tour du moteur */
void IntCC14(void) interrupt 0x1E {
	nbtours++;
}




void main(){
	InitGPIO();
	IEN = 1;
	while(1);
}
