/**
 * Copyright (c) 2011 Anup Patel.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file arm_heap.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief Header file for heap managment
 */

#ifndef __ARM_HEAP_H_
#define __ARM_HEAP_H_

#include <arm_types.h>

void * arm_malloc(size_t size);
void arm_heap_init(void);

#endif /* __ARM_HEAP_H_ */
