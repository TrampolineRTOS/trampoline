/*
 * libfdt - Flat Device Tree manipulation (build/run environment adaptation)
 * Copyright (C) 2007 Gerald Van Baren, Custom IDEAS, vanbaren@cideas.com
 * Original version written by David Gibson, IBM Corporation.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _LIBFDT_ENV_H
#define _LIBFDT_ENV_H

#include <arm_types.h>
#include <arm_stdio.h>
#include <arm_string.h>

extern struct fdt_header *working_fdt;  /* Pointer to the working fdt */

#define fdt32_to_cpu(x)		be32_to_cpu(x)
#define cpu_to_fdt32(x)		cpu_to_be32(x)
#define fdt64_to_cpu(x)		be64_to_cpu(x)
#define cpu_to_fdt64(x)		cpu_to_be64(x)

#define memmove		arm_memmove
#define memcpy		arm_memcpy
#define memcmp		arm_memcmp
#define memchr		arm_memchr
#define memset		arm_memset
#define strchr		arm_strchr
#define strcpy		arm_strcpy
#define strcmp		arm_strcmp
#define strlen		arm_strlen

#define printf		arm_printf
#define sprintf		arm_sprintf
#define snprintf	arm_snprintf

#endif /* _LIBFDT_ENV_H */
