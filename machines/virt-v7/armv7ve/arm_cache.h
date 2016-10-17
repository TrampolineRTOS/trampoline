/**
 * Copyright (c) 2014 Anup Patel.
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
 * @file arm_cache.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief ARM cache operations Header
 */
#ifndef _ARM_CACHE_H__
#define _ARM_CACHE_H__

#include <arm_types.h>

/** Invalidate all instruction caches */
void arm_invalidate_icache(void);

/** Clean data cache */
void arm_clean_dcache(void);

/** Clean data cache line by MVA range */
void arm_clean_dcache_mva_range(virtual_addr_t start, virtual_addr_t end);

/** Clean and invalidate data cache */
void arm_clean_invalidate_dcache(void);

/** Clean and invalidate data cache line by MVA */
void arm_clean_invalidate_dcache_mva(virtual_addr_t mva);

/** Clean and invalidate data cache lines by MVA range */
void arm_clean_invalidate_dcache_mva_range(virtual_addr_t start,
					   virtual_addr_t end);

#endif
