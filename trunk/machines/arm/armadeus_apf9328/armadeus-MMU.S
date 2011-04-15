/**
 * @file olimex_tpl_sleep.S
 *
 * @section descr File description
 *
 * Implementation of tpl_sleep function, called by idle task
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */



MMU_SECTION	= 0x02
TTBit	 = 0x10
Domain	 = 0x1e0
FullAccess	= 0xc00
CACHE_CONF = 0xc

MMU_TABLE	= 0x08000000 + 0x01000000 -0x4000 

#define MMU_MAP(x,cache) mov r2,#Section|TTBit|(cache) ; orr	r2,r2,#Domain|FullAccess ; orr	r2,r2,#(x)<<20 ; str	r2,[r12,#(x)*4]

.global readstate
readstate:
  mrc	p15,0,r0,c1,c0,0
  mov pc,lr
 
.global init_mmu
init_mmu:
    stmdb sp!, {r4-r11}

/* disable MMU (just in case ... )*/
mov	r0,#0x78
mcr	p15,0,r0,c1,c0,0

mov	r0,#0
mcr	p15,0,r0,c7,c7,0	/* invalidate caches */
mcr	p15,0,r0,c8,c7,0	/* invalidate TLBs*/

ldr	r0,=MMU_TABLE
mcr	p15,0,r0,c2,c0,0	/* set base*/

mov	r1,r0
mov	r2,#4096
mov	r3,#0
init_tlb:
subs	r2,r2,#1
str	r3,[r1],#4
bne	init_tlb


ldr	r12,=MMU_TABLE







/** Alliasing a region */
/*add	r0,r12,#0x000


/** other one work !!!!*/

/*add	r0,r12,#0x000
mov	r1,#4096
sub r1,r1,#1
mov	r2,#MMU_SECTION|TTBit
orr	r2,r2,#Domain|FullAccess
orr	r2,r2,#0x0000000
*/
#21c000
#TEST
add	r0,r12,#0x0

mov	r2,#MMU_SECTION|TTBit
orr	r2,r2,#Domain|FullAccess
orr	r2,r2,#0x08000000
str	r2,[r0]


/*
Assignation nouvelle région avec un seul niveau

add	r0,r12,INDEX d'entrée dans la TLB de 4 en 4 

mov	r2,#MMU_SECTION|TTBit|CACHE_CONF
orr	r2,r2,#Domain|FullAccess
orr	r2,r2,ADRESSE de base de la page en multiple de 0x00100000
str	r2,[r0]

*/

#END TEST

add	r0,r12,#0x0004
mov	r1,#4096
sub r1,r1,#2
mov	r2,#MMU_SECTION|TTBit
orr	r2,r2,#Domain|FullAccess
orr	r2,r2,#0x00100000

init_tlb1:
subs	r1,r1,#1
str	r2,[r0],#4
add	r2,r2,#0x00100000
bne	init_tlb1


// change the 0x08000000 adresse range to be cacheable
add	r0,r12,#512

mov	r2,#MMU_SECTION|TTBit|CACHE_CONF
orr	r2,r2,#Domain|FullAccess
orr	r2,r2,#0x08000000
str	r2,[r0]

	
	
/* init domains*/
mov	r0,#3<<30
mcr	p15,0,r0,c3,c0,0

ldr	r12,=AFTER_REMAP
mrc	p15,0,r0,c1,c0,0
// data cache and MMU on
orr	r0,r0,#5	
// MMU on only
// orr	r0,r0,#1	
// data cache on only
//orr	r0,r0,#4	

orr	r0,r0,#1<<12	// ICache enabled
orr	r0,r0,#1<<31	// 
orr	r0,r0,#1<<30	// These two select asynchronous clicking mode
orr	r0,r0,#1<<1	  // Fault checking enabled
orr r0,r0,#1<<14  // Round Robin DCache replacement policy
mcr	p15,0,r0,c1,c0,0
#bx	r12
nop
nop
nop
nop
nop
AFTER_REMAP:	

	

nop
nop
nop
/*
ledOn:  mov r0,#0x0021c000 /*en réalité adresse réelle 21c000*/
				
	/*	add r0, r0, #0x300
		mov r1,#0xffffffff
		str r1,[r0]
		NOP
		NOP
		NOP

	*/
	#END CODE


  ldmia sp!, {r4-r11}
    # return value goes into r0, here it's zero
    mov r0, #0
mov pc,lr
