/*=======================================================================================
	Auteur TR
	12 Mai 2010
	Processeur : STM32F103RB
	Logiciel dev : µVision 4
	Module qui configure les I/O
________________________________________________________________________________________
REVS
	[PEH 01/11/2010] Remise en forme des prototypes et passage par mode 
	de la configuration au lieu de techno et sens
________________________________________________________________________________________
TODO

=======================================================================================*/

#ifndef _GPIO_H__
#define _GPIO_H__

#include "stm_regs.h" 

#define INPUT_FLOATING		 			4 
#define INPUT_PULL_UP 		 			8 
#define INPUT_PULL_DOWN		 			8 
#define ANALOG_INPUT					0 
#define OUTPUT_OPEN_DRAIN 				5 
#define OUTPUT_PUSH_PULL				1 
#define ALTERNATE_FUNCTION_PUSH_PULL 	9 
#define ALTERNATE_FUNCTION_OPEN_DRAIN 	13

/**
* Initialize a pin of a GPIO with max. output speed 10 MHz 
* @param port to configure	[GPIOA..GPIOC]
* @param pin to configure	[0...15]
* @param mode selected		(see definitions to select the mode)
**/
void Port_IO_Init(GPIO_TypeDef * port, u8 pin, u8 mode);

/**
* Initialize a pin of a GPIO as an external interreput
* @param port to configure	[GPIOA..GPIOC]
* @param pin to configure	[0...15]
* @param mode selected		(see definitions to select the mode)
**/
void Port_IO_Init_As_EXTI(GPIO_TypeDef * port, u8 pin, u8 mode);

/**
*  Set the state of a pin
* @param port's pin	 [GPIOA..GPIOC]
* @param pin to set [0..15]
**/
void Port_IO_Set(GPIO_TypeDef * port, u8 pin);

/**
* Clear the state of a pin
* @param port's pin	 [GPIOA..GPIOC]
* @param pin to clear [0..15]
**/void Port_IO_Clr(GPIO_TypeDef * port, u8 pin);

/**
*  Toggle the state of a pin
* @param port's pin	 [GPIOA..GPIOC]
* @param pin to toggle [0..15]
**/
void Port_IO_Toggle(GPIO_TypeDef * port, u8 pin);

/**
*  Read the state of a pin
* @param port's pin	 [GPIOA..GPIOC]
* @param pin to read [0..15]
* @value return the state of the pin
**/
u8 Port_IO_Read(GPIO_TypeDef * port, u8 pin);

#endif
