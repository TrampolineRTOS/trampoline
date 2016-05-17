/**
 * \file
 *
 * \brief Instance description for USB
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAMD11_USB_INSTANCE_
#define _SAMD11_USB_INSTANCE_

/* ========== Register definition for USB peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_USB_CTRLA              (0x41005000U) /**< \brief (USB) Control A */
#define REG_USB_SYNCBUSY           (0x41005002U) /**< \brief (USB) Synchronization Busy */
#define REG_USB_QOSCTRL            (0x41005003U) /**< \brief (USB) USB Quality Of Service */
#define REG_USB_FSMSTATUS          (0x4100500DU) /**< \brief (USB) Finite State Machine Status */
#define REG_USB_DESCADD            (0x41005024U) /**< \brief (USB) Descriptor Address */
#define REG_USB_PADCAL             (0x41005028U) /**< \brief (USB) USB PAD Calibration */
#define REG_USB_DEVICE_CTRLB       (0x41005008U) /**< \brief (USB) DEVICE Control B */
#define REG_USB_DEVICE_DADD        (0x4100500AU) /**< \brief (USB) DEVICE Device Address */
#define REG_USB_DEVICE_STATUS      (0x4100500CU) /**< \brief (USB) DEVICE Status */
#define REG_USB_DEVICE_FNUM        (0x41005010U) /**< \brief (USB) DEVICE Device Frame Number */
#define REG_USB_DEVICE_INTENCLR    (0x41005014U) /**< \brief (USB) DEVICE Device Interrupt Enable Clear */
#define REG_USB_DEVICE_INTENSET    (0x41005018U) /**< \brief (USB) DEVICE Device Interrupt Enable Set */
#define REG_USB_DEVICE_INTFLAG     (0x4100501CU) /**< \brief (USB) DEVICE Device Interrupt Flag */
#define REG_USB_DEVICE_EPINTSMRY   (0x41005020U) /**< \brief (USB) DEVICE End Point Interrupt Summary */
#define REG_USB_DEVICE_ENDPOINT_EPCFG0 (0x41005100U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 0 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR0 (0x41005104U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 0 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET0 (0x41005105U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 0 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS0 (0x41005106U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 0 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG0 (0x41005107U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 0 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR0 (0x41005108U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 0 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET0 (0x41005109U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 0 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG1 (0x41005120U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 1 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR1 (0x41005124U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 1 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET1 (0x41005125U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 1 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS1 (0x41005126U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 1 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG1 (0x41005127U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 1 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR1 (0x41005128U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 1 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET1 (0x41005129U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 1 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG2 (0x41005140U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 2 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR2 (0x41005144U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 2 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET2 (0x41005145U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 2 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS2 (0x41005146U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 2 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG2 (0x41005147U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 2 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR2 (0x41005148U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 2 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET2 (0x41005149U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 2 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG3 (0x41005160U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 3 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR3 (0x41005164U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 3 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET3 (0x41005165U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 3 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS3 (0x41005166U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 3 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG3 (0x41005167U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 3 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR3 (0x41005168U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 3 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET3 (0x41005169U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 3 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG4 (0x41005180U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 4 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR4 (0x41005184U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 4 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET4 (0x41005185U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 4 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS4 (0x41005186U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 4 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG4 (0x41005187U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 4 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR4 (0x41005188U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 4 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET4 (0x41005189U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 4 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG5 (0x410051A0U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 5 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR5 (0x410051A4U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 5 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET5 (0x410051A5U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 5 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS5 (0x410051A6U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 5 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG5 (0x410051A7U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 5 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR5 (0x410051A8U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 5 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET5 (0x410051A9U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 5 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG6 (0x410051C0U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 6 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR6 (0x410051C4U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 6 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET6 (0x410051C5U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 6 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS6 (0x410051C6U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 6 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG6 (0x410051C7U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 6 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR6 (0x410051C8U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 6 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET6 (0x410051C9U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 6 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG7 (0x410051E0U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 7 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR7 (0x410051E4U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 7 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET7 (0x410051E5U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 7 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS7 (0x410051E6U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 7 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG7 (0x410051E7U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 7 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR7 (0x410051E8U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 7 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET7 (0x410051E9U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 7 */
#else
#define REG_USB_CTRLA              (*(RwReg8 *)0x41005000U) /**< \brief (USB) Control A */
#define REG_USB_SYNCBUSY           (*(RoReg8 *)0x41005002U) /**< \brief (USB) Synchronization Busy */
#define REG_USB_QOSCTRL            (*(RwReg8 *)0x41005003U) /**< \brief (USB) USB Quality Of Service */
#define REG_USB_FSMSTATUS          (*(RoReg8 *)0x4100500DU) /**< \brief (USB) Finite State Machine Status */
#define REG_USB_DESCADD            (*(RwReg  *)0x41005024U) /**< \brief (USB) Descriptor Address */
#define REG_USB_PADCAL             (*(RwReg16*)0x41005028U) /**< \brief (USB) USB PAD Calibration */
#define REG_USB_DEVICE_CTRLB       (*(RwReg16*)0x41005008U) /**< \brief (USB) DEVICE Control B */
#define REG_USB_DEVICE_DADD        (*(RwReg8 *)0x4100500AU) /**< \brief (USB) DEVICE Device Address */
#define REG_USB_DEVICE_STATUS      (*(RoReg8 *)0x4100500CU) /**< \brief (USB) DEVICE Status */
#define REG_USB_DEVICE_FNUM        (*(RoReg16*)0x41005010U) /**< \brief (USB) DEVICE Device Frame Number */
#define REG_USB_DEVICE_INTENCLR    (*(RwReg16*)0x41005014U) /**< \brief (USB) DEVICE Device Interrupt Enable Clear */
#define REG_USB_DEVICE_INTENSET    (*(RwReg16*)0x41005018U) /**< \brief (USB) DEVICE Device Interrupt Enable Set */
#define REG_USB_DEVICE_INTFLAG     (*(RwReg16*)0x4100501CU) /**< \brief (USB) DEVICE Device Interrupt Flag */
#define REG_USB_DEVICE_EPINTSMRY   (*(RoReg16*)0x41005020U) /**< \brief (USB) DEVICE End Point Interrupt Summary */
#define REG_USB_DEVICE_ENDPOINT_EPCFG0 (*(RwReg8 *)0x41005100U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 0 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR0 (*(WoReg8 *)0x41005104U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 0 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET0 (*(WoReg8 *)0x41005105U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 0 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS0 (*(RoReg8 *)0x41005106U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 0 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG0 (*(RwReg8 *)0x41005107U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 0 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR0 (*(RwReg8 *)0x41005108U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 0 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET0 (*(RwReg8 *)0x41005109U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 0 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG1 (*(RwReg8 *)0x41005120U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 1 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR1 (*(WoReg8 *)0x41005124U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 1 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET1 (*(WoReg8 *)0x41005125U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 1 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS1 (*(RoReg8 *)0x41005126U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 1 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG1 (*(RwReg8 *)0x41005127U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 1 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR1 (*(RwReg8 *)0x41005128U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 1 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET1 (*(RwReg8 *)0x41005129U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 1 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG2 (*(RwReg8 *)0x41005140U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 2 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR2 (*(WoReg8 *)0x41005144U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 2 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET2 (*(WoReg8 *)0x41005145U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 2 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS2 (*(RoReg8 *)0x41005146U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 2 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG2 (*(RwReg8 *)0x41005147U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 2 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR2 (*(RwReg8 *)0x41005148U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 2 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET2 (*(RwReg8 *)0x41005149U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 2 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG3 (*(RwReg8 *)0x41005160U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 3 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR3 (*(WoReg8 *)0x41005164U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 3 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET3 (*(WoReg8 *)0x41005165U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 3 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS3 (*(RoReg8 *)0x41005166U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 3 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG3 (*(RwReg8 *)0x41005167U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 3 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR3 (*(RwReg8 *)0x41005168U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 3 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET3 (*(RwReg8 *)0x41005169U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 3 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG4 (*(RwReg8 *)0x41005180U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 4 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR4 (*(WoReg8 *)0x41005184U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 4 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET4 (*(WoReg8 *)0x41005185U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 4 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS4 (*(RoReg8 *)0x41005186U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 4 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG4 (*(RwReg8 *)0x41005187U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 4 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR4 (*(RwReg8 *)0x41005188U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 4 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET4 (*(RwReg8 *)0x41005189U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 4 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG5 (*(RwReg8 *)0x410051A0U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 5 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR5 (*(WoReg8 *)0x410051A4U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 5 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET5 (*(WoReg8 *)0x410051A5U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 5 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS5 (*(RoReg8 *)0x410051A6U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 5 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG5 (*(RwReg8 *)0x410051A7U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 5 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR5 (*(RwReg8 *)0x410051A8U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 5 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET5 (*(RwReg8 *)0x410051A9U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 5 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG6 (*(RwReg8 *)0x410051C0U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 6 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR6 (*(WoReg8 *)0x410051C4U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 6 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET6 (*(WoReg8 *)0x410051C5U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 6 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS6 (*(RoReg8 *)0x410051C6U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 6 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG6 (*(RwReg8 *)0x410051C7U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 6 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR6 (*(RwReg8 *)0x410051C8U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 6 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET6 (*(RwReg8 *)0x410051C9U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 6 */
#define REG_USB_DEVICE_ENDPOINT_EPCFG7 (*(RwReg8 *)0x410051E0U) /**< \brief (USB) DEVICE_ENDPOINT End Point Configuration 7 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSCLR7 (*(WoReg8 *)0x410051E4U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Clear 7 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUSSET7 (*(WoReg8 *)0x410051E5U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status Set 7 */
#define REG_USB_DEVICE_ENDPOINT_EPSTATUS7 (*(RoReg8 *)0x410051E6U) /**< \brief (USB) DEVICE_ENDPOINT End Point Pipe Status 7 */
#define REG_USB_DEVICE_ENDPOINT_EPINTFLAG7 (*(RwReg8 *)0x410051E7U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Flag 7 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENCLR7 (*(RwReg8 *)0x410051E8U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Clear Flag 7 */
#define REG_USB_DEVICE_ENDPOINT_EPINTENSET7 (*(RwReg8 *)0x410051E9U) /**< \brief (USB) DEVICE_ENDPOINT End Point Interrupt Set Flag 7 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for USB peripheral ========== */
#define USB_EPT_NBR                 8        // Number of USB end points (obsolete)
#define USB_EPT_NUM                 8        // Number of USB end points
#define USB_GCLK_ID                 6        // Index of Generic Clock
#define USB_PIPE_NUM                8        // Number of USB pipes

#endif /* _SAMD11_USB_INSTANCE_ */
