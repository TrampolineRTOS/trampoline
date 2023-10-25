/*
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

#ifndef _ARDUINO_CORE_CORTEX_M_VECTORS_H_
#define _ARDUINO_CORE_CORTEX_M_VECTORS_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _CoreVectors
{
  /* Stack pointer */
  void* pvStack;

  /* Cortex-M handlers */
  // void* pfnReset_Handler;
  // void* pfnNMI_Handler;
  // void* pfnHardFault_Handler;
  // void* pfnMemManage_Handler;
  // void* pfnBusFault_Handler;
  void* pfnUsageFault_Handler;
  void* pfnReserved1_Handler;
  void* pfnReserved2_Handler;
  void* pfnReserved3_Handler;
  void* pfnReserved4_Handler;
  // void* pfnSVC_Handler;
  // void* pfnDebugMon_Handler;
  void* pfnReserved5_Handler;
  // void* pfnPendSV_Handler;
  // void* pfnSysTick_Handler;
} CoreVectors;

/**
 * \brief Default interrupt handler for unused IRQs.
 */
extern void vector_halt(void);

/*
 * \brief Set new core vectors base.
 *
 * \param pBase pointer on vector table.
 *
 * \return Previous vector table address.
 */
extern void* vectorSetOrigin(DeviceVectors* pBase);

/*
 * \brief Assign a new handler to the given vector.
 *
 * \param number Vector index.
 * \param isr    Function pointer.
 *
 * \return Previous vector handler.
 */
extern void* vectorAssign(IRQn_Type number, void (*isr)(void));

/*
 * \brief Reset handler of the given vector to default.
 *
 * \param number Vector index.
 *
 * \return Previous vector handler.
 */
extern void* vectorReset(IRQn_Type number);

#ifdef __cplusplus
}
#endif

#endif // _ARDUINO_CORE_CORTEX_M_VECTORS_H_
