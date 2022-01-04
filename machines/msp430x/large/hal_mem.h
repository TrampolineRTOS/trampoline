#ifndef __HAL_MEM__
#define __HAL_MEM__

/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Include device specific header file                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <msp430.h>
#include "stdint.h"
#include "stdbool.h"

/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Access abstraction to registers                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define HWREG32(x) (*((volatile uint32_t *)((uint16_t)x)))
#define HWREG16(x) (*((volatile uint16_t *)((uint16_t)x)))
#define HWREG8(x) (*((volatile uint8_t *)((uint16_t)x)))

#endif /* #ifndef __HAL_MEM__ */
