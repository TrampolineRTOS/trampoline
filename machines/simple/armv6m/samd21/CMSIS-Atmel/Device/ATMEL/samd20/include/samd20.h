/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */
#ifndef _SAMD20_
#define _SAMD20_

#if defined (__SAMD20E14__)
#include "samd20e14.h"
#elif defined (__SAMD20E15__)
#include "samd20e15.h"
#elif defined (__SAMD20E16__)
#include "samd20e16.h"
#elif defined (__SAMD20E17__)
#include "samd20e17.h"
#elif defined (__SAMD20E18__)
#include "samd20e18.h"
#elif defined (__SAMD20E1F__)
#include "samd20e1f.h"
#elif defined (__SAMD20G14__)
#include "samd20g14.h"
#elif defined (__SAMD20G15__)
#include "samd20g15.h"
#elif defined (__SAMD20G16__)
#include "samd20g16.h"
#elif defined (__SAMD20G17__)
#include "samd20g17.h"
#elif defined (__SAMD20G18__)
#include "samd20g18.h"
#elif defined (__SAMD20G17U__)
#include "samd20g17u.h"
#elif defined (__SAMD20G18U__)
#include "samd20g18u.h"
#elif defined (__SAMD20J14__)
#include "samd20j14.h"
#elif defined (__SAMD20J15__)
#include "samd20j15.h"
#elif defined (__SAMD20J16__)
#include "samd20j16.h"
#elif defined (__SAMD20J17__)
#include "samd20j17.h"
#elif defined (__SAMD20J18__)
#include "samd20j18.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAMD20_ */
