/***************************************************************************/
/*

FILE
	__ppc_eabi_init.c
	$Date: 2012/11/02 13:29:27 $
	$Revision: 1.3 $
	
DESCRIPTION

	Use this file for C or C++.  Contains calls to initialize memory pools
	for use with malloc/free, exceptions and static initializers.  If your
	project does not use exceptions, then the initialization code for them 
	is stripped out.  If they are used, the linker will add them 
	automatically.  A C-only program will be a little smaller (160 bytes) 
	with __ppc_eabi_init.c.

	Interface for board-level initialization and user-level initialization.
	
	If hardware initialization and pre-main user initialization are required,
	copy this file to your project directory and customize it (instead of
	customizing __start.c).
	
	Note that __init_hardware should not write on the stack until the
	memory controller is properly configured.

	
	void __init_hardware(void)
	
		Initialize the hardware, including the memory controller.
	
	void __init_user(void)
	
		Allow the user to perform initialization before calling main().
	
	void __init_cpp(void)
	
		CodeWarrior C++ initialization before calling main().  Calls
		constructors of which the cpp exception handling initialization
		is the first constructor, if exceptions are used.
	
	void __fini_cpp(void)
	
		Calls destructors.
	
	void _ExitProcess(void)
 		
 		This function simply stalls the debugger.  You may want to rewrite this
 		function if you are using an OS.
	
 	abort and exit
 
 	In order to correctly implement the required startup/termination sequence for
 	C and C++ programs, we need to have an exit() routine that can be called by
 	the program startup code. The exit() routine is supposed to
 
 		(1)	call any functions registered via atexit()
 		(2) call destructors for any global objects
 		(3)	flush any unwritten buffers, close any open files, etc.
 		(4) terminates the program
 
 	We don't, however, want to require the ANSI C library for every CodeWarrior
 	program, since it drags in lots of code that may not be needed.
 
 	Instead we provide a dummy exit() function which simply calls the destructors
 	and terminates the program. We assume that any program which uses atexit()
 	or <stdio.h> and which requires those cleanup behaviors will have linked with
 	the ANSI C library, whose definition of exit() will override the one here.
 
 	We similarly define a dummy abort() function (which is called by the default
 	terminate() handler).
 
 	Programs which rely on the proper ANSI C/C++ behavior must use the ANSI C
 	library, and order it in the CodeWarrior project or command-line so that
 	its definitions supersede these definitions in the runtime support library.

COPYRIGHT	
	(c) 2002-2006 Freescale Semiconductor, Inc.
	All rights reserved.

HISTORY
	97 APR 17 LLY	Created.
	97 JUN 24 MEA	Added support for C++ and malloc memory heaps.
	97 JUN 26 MEA	Made C and C++ versions of this file.  Added abort and exit.
	97 JUL 17 SCM	Customized for MPC821 ADS board.
	97 JUL 20 MEA	Changed __exit to _ExitProcess so as not to conflict with EWL.
					_ExitProcess added to this file; removed form __start.c.
	99 JAN 22 MEA	Removed exception handing to __init_cpp_exceptions.c for use
					with 2.2.2 compiler (post Release 4).  Put prototypes for
					exit and abort within extern "C" to avoid name-mangling.
        2012 NOV 02 CH  Add __SPE__ macro

*/
/***************************************************************************/

#pragma exceptions off
#pragma ANSI_strict off
#pragma only_std_keywords off

#define ALLOC_ADDITIONAL_HEAPS 0
#include "MPC5674F.h"
#define FLASH_REG FLASH_A.BIUCR.R
#define FLASH_DATA 0x00B86B00 /* For 200MHz versions use 0x00B8A500 */
#define FLASH_REG2 FLASH_B.BIUCR.R
#define FLASH_DATA2 0x00B86B00 /* For 200MHz versions use 0x00B8A500 */


#include <__ppc_eabi_init.h>
#include <__ppc_eabi_linker.h>		/* linker-generated symbol declarations */
#if ALLOC_ADDITIONAL_HEAPS
#include <pool_alloc.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

static void __init_cpp(void);
static void __fini_cpp(void);
typedef void (*voidfunctionptr) (void);	/* ptr to function returning void */
__declspec(section ".init") extern voidfunctionptr _ctors[];
__declspec(section ".init") extern voidfunctionptr _dtors[];
__declspec(weak) extern void abort(void);
__declspec(weak) extern void exit(int status);
extern void usr_init();
__declspec(section ".init") static int __get_runtime_linktime_delta(void);
__declspec(section ".init") static int __get_linktime_address(void);
__declspec(section ".init") static void __mwerks_fixup_relocations(void);
void FlashConfig(void);

#ifdef __cplusplus
}
#endif

/***************************************************************************/
/*
 *	__init_hardware
 *
 *	Initialize the processor and board.
 *
 *	Note: this function must not access memory until the memory controller
 *	is initialized.  Using "fralloc" (frame allocate) or writing this
 *	function in C will cause this routine to break because writing into
 *	stack memory is not valid until after usr_init returns.
 */
/***************************************************************************/

asm void __init_hardware(void)
{
	/*
	 *	Initialize board unless running with MWDebug.
	 *	Uncomment the initialization below if running standalone. 
	 *	You may need to perform other initializations.
	 */
	nofralloc

   /*
	* If we are using Hardware  floating point we need to make sure
 	* to enable the FP bit in the  MSR
 	*/	

#if __option(floatingpoint)==1 &&  __option(sfp_emulation)==0
 	mfmsr r3
 	ori  r3,r3,0x00002000
 	mtmsr r3
#endif

   /*
	* If we have selected Altivec Programming Model we need to make sure
 	* to enable the Altivec bit in the  MSR
 	*/	

#if __VEC__
 	mfmsr r3
	oris r3,r3,0x0200
 	mtmsr r3
#endif	

   /*
	* Enable the MSR[SPE] bit for e500/Zen
 	*/	

#if (defined (__PPCZen__) && defined(__SPE__)) || defined(__PPCe500__) || defined(__PPCe500v2__)
	mfmsr r3
	oris   r3,r3,0x0200
	mtmsr r3
#endif

	/*
	 *	When customizing, be aware that the memory controller may not be
	 *	configured.
	 */

#if defined(ROM_VERSION) || defined(CACHE_VERSION) || defined(CALL_USR_INIT)
	mflr	r31						/* save off return address in NV reg */
	bl		usr_init				/* init board hardware */
	mtlr	r31						/* get saved return address */
#endif

	blr
}

#if ALLOC_ADDITIONAL_HEAPS
static void AllocMoreHeaps(void)
{
	/*
	 *	By default, we EWL's allocation (malloc/free) even with C++.
	 *	If you have declared a heap size in the Project Pref panel,
	 *	a defaull heap will be created the first time you call
	 *	malloc.  You can add more calls to init_alloc to create additional
	 *	heaps.
	 */
	init_alloc(some_address1, some_size1);
	init_alloc(some_address2, some_size2);
}
#endif
void FlashConfig(void) 
{
		unsigned int mem_write_code [] = {

		#if __option(vle)
			/*for processors which support VLE only or for 'VLE on' option*/
    		0xD0344400, /* stw r3,(0)r4 machine code: writes r3 contents to addr in r4 then se_nop*/
    		0x7C0006AC, /* mbar machine code: ensure prior store completed */
    		0x44000004  /* blr machine code: branches to return address in link register */
		#else
   			0x90640000, /* stw r3,(0)r4 machine code: writes r3 contents to addr in r4 */
   			0x7C0006AC, /* mbar machine code: ensure prior store completed */
   			0x4E800020  /* blr machine code: branches to return address in link register */
		#endif // __option(vle)

			};
	

typedef void (*mem_write_code_ptr_t)(unsigned int, unsigned int);

  #if defined(FLASH_REG) 
  (*((mem_write_code_ptr_t)mem_write_code)) 	/* cast mem_write_code as func ptr*/
                                 /* * de-references func ptr, i.e. converts to func*/
     (FLASH_DATA,            /* which passes integer (in r3) */
      (unsigned int)&FLASH_REG);
  #endif      
      
  #if defined(FLASH_REG2)
  	(*((mem_write_code_ptr_t)mem_write_code)) 	/* cast mem_write_code as func ptr*/
                                 /* * de-references func ptr, i.e. converts to func*/
     (FLASH_DATA2,            /* which passes integer (in r3) */
      (unsigned int)&FLASH_REG2);
  #endif 
 
}

asm void __init_user(void)
{
	fralloc
	/*
	 *	Allocate additional heaps.
	 */
#if ALLOC_ADDITIONAL_HEAPS
	bl		AllocMoreHeaps
#endif

	/*
	 *	initialization of static initializers
	 */
#if (defined(__cplusplus) || defined(__VEC__) || defined(__SPE__)) && !defined(DO_NOT_LOAD_CTORS_DTORS)
	bl		__init_cpp
#endif
	bl FlashConfig
	/*
	 *	Add your initializations here.
	 */
	frfree
	blr
}

#if defined(__cplusplus) || defined(__VEC__) || defined(__SPE__)
static void __init_cpp(void)
{
	voidfunctionptr *constructor;

	/*
	 *	call static initializers
	 */
	for (constructor = _ctors; *constructor; constructor++) {
		(*constructor)();
	}
}

static void __fini_cpp(void)
{
	voidfunctionptr *destructor;

	/*
	 *	call destructors
	 */
	for (destructor = _dtors; *destructor; destructor++) {
		(*destructor)();
	}
}
#endif

extern void abort(void)
{
	_ExitProcess();
}

extern void exit(int status)
{
	#pragma unused(status)

#if (defined(__cplusplus) || defined(__VEC__)) && !defined(DO_NOT_LOAD_CTORS_DTORS)
	__fini_cpp();
#endif
	_ExitProcess();
}


/*
 *	_ExitProcess
 *
 *	PowerPC EABI Runtime termination
 */
asm void _ExitProcess(void)
{
	nofralloc

#if VLE_ON
	/* the inline assembler can not translate this instruction */
	se_illegal							/* arbitrary break trap for halt */
#else
	opword 0x00454E44					/* arbitrary break trap for halt */
#endif
}

/****************************************************************************/
/*
 *	__flush_cache
 *
 *	For the given memory range, forces all modified data cache contents to be 
 *	written to memory and invalidates the associated instruction cache
 *	entries.
 *	
 */
/****************************************************************************/
asm void __flush_cache(register void *address, register unsigned int size)
{
#pragma unused (address, size)
	/* r3 is address, r4 is size */
	nofralloc

#if !defined( __PPC555__ ) && !defined( __PPC56X__ )
#if VLE_ON
	/* the inline assembler can not translate 2 instructions into 1 */
	e_li    r5,0xFFFFFFF1
#else
	lis		r5, 0xffff
	ori		r5, r5, 0xfff1
#endif
	and		r5, r5, r3				/* make address 8-byte aligned		*/
	subf	r3, r5, r3				/* get unaligned-aligned difference	*/
	add		r4, r4, r3				/* increase size accordingly		*/

rept:
/*
** Note: If no data cache, then just invalidate the instruction
** cache entry.
**
** The MPC 5xx processors do not have data cache.
*/
#if !defined( __PPC505__ ) && !defined( __PPC509__ )

#if !defined(__PPCGENERIC__)
	dcbst	0,r5
#endif

#endif

#if defined(__PPCZen__) || defined(__PPCe500__) || defined(__PPCe500v2__)
#if VLE_ON
	se_isync
#else
	msync
#endif
#else
	sync
#endif

	
#if !defined(__PPCGENERIC__)
	icbi	0,r5
#endif

	addic	r5,r5,0x8
	subic.	r4,r4,0x8
	bge		rept
	isync
#endif
	blr
}

#if __option(sda_pic_pid)
/* The following functions are used with SDA PIC/PID support.  						*/
/* __init_registers and __init_data will overload weak versions found in __start.c	*/

/***************************************************************************
*** Requirements for SDA PIC/PID ***

The basic requirement for SDA PIC/PID is that the startup code (.init) and
the segments .sdata and .sdata2 all maintain their link time address 
relationship at runtime.  In other words if the link time addresses are:
.init = 0x00002000
.sdata2 = 0x00003000
.sdata = 0x00004000
but that .init somehow is executed at 0x00002500, then those link time 
addresses must all increment by 0x00000500 for their runtime addresses.  
Any segment that does not maintain the address relationship at runtime is 
considered external and must be addressed with absolute addresses.  
Segments that do maintain their link time address relationship at runtime 
are considered internal and must be addressed with pc and sda relative 
addressing.  More on external and internal segments, below.

Having .init, .sdata2 and .sdata, as well as other internal segments, end
up at runtime without the link time relationship is not detected in this
runtime but it is at least technically possible for someone to modify the
runtime to support this, at least for a specific application.

*** Internal and External segments and references ***

At link time, the linker determines whether code and data segments are 
external or internal.  Internal segments reference their data as far or 
near offsets of the small data registers r2 and r13.  Their code 
references are normally pc relative, but if far code references are 
required, they also use offsets of the small data registers.  Internal
segments can also reference code and data in other internal segments
with the same addressing that they would use for their own code ad data.
By default, all segments in your application are considered internal with 
one exception listed below.

External segments are segments that are at absolute addresses.  
Segments with a name like .abs.xxxxxxxx, where xxxxxxxx is a hex address
are considered external.  External segments reference their data with 
absolute addressing and code references within the segment can be pc 
relative or absolute.  Any other segment must use absolute references 
to reference code or data in external segments.  External segments must 
reference an internal segment with small data registers for code and data.

Akin to external segments are external symbol references.  These are 
symbols, usually linker generated symbols, that are determined to be not 
within any segment in your application.  They will be referenced with
absolute addressing.  All symbols in an external segment are considered
to be external symbol references.

The ldf has 2 mechanisms for you to override the linker's defaults:
1.  The MEMORY directive now supports 
addr_mode = external | internal // default is internal
addr_mode is ignored unless you have chosen the SDA PIC/PID ABI in the EPPC 
Target Pref panel.

2. New directives INTERNAL_SYMBOL and EXTERNAL_SYMBOL can be used to force
the addressing of global symbols.  These directives are of the 
form XXXL_SYMBOL { sym1, sym2, symN } where the symbols are the link time
symbol names (mangled for c++).

The auto-generated linker defined start and end symbols for loadable 
segments are internal if they are addresses into internal segments and 
external if they are for external segments.  All other linker defined 
symbols you create in a lcf are considered external unless you redefine
them with INTERNAL_SYMBOL.  The linker also defines some linker defined 
symbols for its own use and they have the following default settings:

_stack_addr [top of the stack - comes from pref panel settings] external
_stack_end [bottom of the stack - comes from pref panel settings] external
_heap_addr [bottom of the heap - comes from pref panel settings] external
_heap_end [top of the heap - comes from pref panel settings] external
// the next two need to be treated as internal to be EABI compliant so
// you may not redefine them.
_SDA_BASE_ [.sdata + 0x00008000] internal
_SDA2_BASE_ [.sdata2 + 0x00008000] internal
// The previous small data pointers rely on the small data registers being
// properly initialized before being accessible.  However, it is hard to
// initialize those pointers without accessing them as absolutes.
// The following two symbols are external versions of _SDA_BASE_ and
// _SDA2_BASE_ which can be used as absolutes.  You may not redefine them.
_ABS_SDA_BASE_ [.sdata + 0x00008000] external
_ABS_SDA2_BASE_ [.sdata2 + 0x00008000] external
// the following are numbers, not addresses and they must be treated
// as external.  You may not redefine them.
_nbfunctions [number of functions in program - deprecated] external
SIZEOF_HEADERS [size of the segment headers in a linux app] external

Especially note that the stack and heap linker generated symbols are
external.  It may be more practical in a SDA PIC/PID application to
make the heap and stack be contiguous with an internal segment and
define them as internal.

*** Uses for SDA PIC/PID ***

The runtime was developed for 3 different situations:

1. All code and data segments are internal.  The simplest case would be
for all segments to use the same MEMORY directive and to have all of the 
bss type segments at the end.  In such a simple case, the application could
be converted to a binary file and linked into another application which
could copy it to ram and jump to its entry point.

2. All of the essential segments are internal and therefore moveable but 
there may be some external segments which are absolute.  This situation is 
probably difficult to test but you can download the entire application
to the chip and at least debug it at its link time addresses.

3. Like 2, there are internal and external segments but the application is 
linked as a ROM image - the application does not need to be flashed to
ROM, however.  It is possible to change the ROM Image Address to be an
address into RAM and have the debugger download the image to the RAM 
address.  Alternatively, you could have the ROM image converted to a bin
file and link it into another application as in 1, above.  The structures 
used in __init_data(), _rom_copy_info and __bss_init_info, have been 
modified for SDA PIC/PID to have an extra field which tells the runtime 
where the segment is internal or external so that the internal segments 
will be copied to position relative addresses and the external segments 
will be copied to absolute addresses.

*** Compiler/Linker support for SDA Addressing ***
You build a SDA PIC/PID application by selecting SDA PIC/PID in the ABI
popup in the EPPC Target Preference panel.  When you chose that, the 
compiler will define a simple that you can use to guard PIC/PID source.

#if __option(sda_pic_pid) // is true if you have chosen SDA PIC/PID ABI

If you then link, the linker will generate a table for the runtime files
__ppc_eabi_init.cpp/__ppc_eabi_init.c to use.  If your application has
absolute addressing relocations (which it would by default) you will
probably get linker warnings telling you that those relocations may
cause a problem.  If that happens, you have two choices.  You can change
the Code Model popup in the EPPC Target Preference panel to be
SDA Based PIC/PID Addressing for all of your sources and libraries, and/or
check the Tune Relocations checkbox in the EPPC Target Preference panel.
This new option is only available for the EABI and SDA PIC/PID ABIs.  For
EABI it changes 14 bit branch relocations to 24 bit branch relocations
only if they can not reach the calling site from the original relocation.
For SDA PIC/PID, it changes absolute addressed references of data from
code to use a small data register instead of r0 and changes absolute
code to code refernces to use the pc relative relocations.  In general,
this will work well for normnal compiled code.  It is always possible
to link in an assembly file that does not behave in a standard way.

Whether you use the Code Model SDA Based PIC/PID Addressing or not,
#pragma section has been modified to accept far_sda_rel for the data_mode
and code_mode options.  If you leave those options out, the compiler
will you the Code Model to determine the appropriate modes.

Absolute Addressing defaults to data_mode = far_abs and code_mode = pc_rel.
SDA Based PIC/PID Addressing defaults to data_mode = far_sda_rel and
code_mode = pc_rel.

***************************************************************************/

/***************************************************************************/
/*
 *	__get_runtime_linktime_delta
 *
 *	Assumes that r13 and r2 are initialized correctly and that they always
 *	stay in the same relationship to each other.
 *
 *	Utility function to get difference between runtime and linktime addresses.
 *
 */
/***************************************************************************/
static asm int __get_runtime_linktime_delta(void)
{
	nofralloc
    /* _ABS_SDA_BASE_, generated by the linker, is the same value as 		 	*/
	/* _SDA_BASE_ but forces the linker to treat it as absolutetly addressed 	*/
	/* and not to substitute r13 for r0.  We therefore end up with r3 exactly 	*/
	/* as calculated at linktime. 												*/
	addis	r3, r0, _ABS_SDA_BASE_@ha
	addi	r3, r3, _ABS_SDA_BASE_@l
   	/* Subtract the runtime from the linktime address.							*/
   	sub		r3,r13,r3
	blr
}

/***************************************************************************/
/*
 *	__mwerks_fixup_relocations
 *
 *	Modify initialized pointers in the data sections to reflect correct
 *	runtime addresses.  The linker created a table, _f_mwerks_fixup, of 
 *	offsets into the data sections that need modification.  This function
 *	loads the pointer at that offset and applies the runtime/linktime
 *	delta.  We wait to call this function until after __init_data.
 *
 */
/***************************************************************************/
static asm void __mwerks_fixup_relocations(void)
{
	nofralloc
	
	/* r13, r2, and r1 have their correct runtime values.						*/

    mflr    r0

   	/* If runtime and linktime addresses are the same, no fixup is necessary.	*/
   	bl		__get_runtime_linktime_delta
    cmpli   cr0,r3,0
    beq     no_fixup

	/* Initialize runtime addresses of the fixup table.  _f_mwerks_fixup is the	*/
	/* beginning of the table and _e_mwerks_fixup is the end.  Note that r0 	*/
	/* will get converted to r13 or r2 by the linker. 							*/
    addis   r5,r0,_f_mwerks_fixup@ha
    addis   r4,r0,_e_mwerks_fixup@ha
    addi    r5,r5,_f_mwerks_fixup@l
    addi    r4,r4,_e_mwerks_fixup@l

    /* Compute number of entries ((_e_mwerks_fixup - _f_mwerks_fixup) / 4).		*/
    subf    r6,r5,r4			
    /* If there are no entries, bail.											*/
    cmpli   cr0,r6,0
    beq     no_fixup
    srwi    r6,r6,2
    mtctr   r6
	/* We use pre-increment, so move to first real entry - 4.					*/
    subi    r5,r5,4
fixup_loop:
	/* Load address of relocation.												*/
    lwzu    r6,4(r5)
    /* Update address using SDA delta.											*/
    add     r6,r6,r3
    /* Load value at relocation.												*/
    lwz	    r7,0(r6)
    /* Update value using SDA delta.											*/
    add     r7,r7,r3
    /* Store updated value.														*/
    stw	    r7,0(r6)
    bdnz    fixup_loop
no_fixup:
    mtlr    r0
    blr
}

/***************************************************************************/
/*
 *	__init_registers
 *
 *	Initialize PowerPC EABI Registers
 *
 *	Note: this function is guaranteed to not reference any memory; the memory
 *	controller may not be initialized.
 *
 *	we now overload the function in the event that the user wants pic pid
 *
 */
/***************************************************************************/
asm extern void __init_registers(void)
{
	nofralloc						/* see above on usage of nofralloc */

    mflr    r0

	/* _ABS_SDA_BASE_, generated by the linker, is the same value as 		 	*/
	/* _SDA_BASE_ but forces the linker to treat it as absolutetly addressed 	*/
	/* and not to substitute r13 for r0.  We therefore end up with r13 exactly 	*/
	/* as calculated at linktime. 												*/
	addis	r13, r0, _ABS_SDA_BASE_@ha
	addi	r13, r13, _ABS_SDA_BASE_@l

	/* _ABS_SDA2_BASE_, generated by the linker, is the same value as 		 	*/
	/* _SDA2_BASE_ but forces the linker to treat it as absolutetly addressed 	*/
	/* and not to substitute r2 for r0.  We therefore end up with r2 exactly 	*/
	/* as calculated at linktime. 												*/
	addis	r2, r0, _ABS_SDA2_BASE_@ha
	addi	r2, r2, _ABS_SDA2_BASE_@l
   
	/* Grab the runtime address of __get_linktime_address.  The bcl will put	*/
	/* __get_linktime_address into LR. */
	bcl 	20,31,__get_linktime_address
entry __get_linktime_address
	/* Move runtime address of __get_linktime_address from LR to r4. */
	mflr	r4

	/* Grab the linktime address of __get_linktime_address.  Note that r0 will	*/
	/* get converted to r13 or r2 by the linker but because r13 and r2 may not	*/
	/* reflect the their runtime values yet, r3 might not equal r4.				*/
    addis   r3,r0,__get_linktime_address@ha
    addi    r3,r3,__get_linktime_address@l
    
   	/* Subtract the runtime from the linktime address.							*/
   	sub		r3,r4,r3
   	/* If runtime and linktime addresses are the same, no fixup is necessary.	*/
    cmpli   cr0,r3,0
    beq     no_fixup

   	/* Add the delta into small data pointers so they will reflect the current 	*/
   	/* position of code and data.												*/
   	add		r13,r13,r3
   	add		r2,r2,r3
no_fixup:

	/* Initialize runtime address of _stack_addr.  Note that r0 will			*/
	/* get converted to r13 or r2 by the linker if _stack_addr is 				*/
	/* treated as an internal symbol (default is external).						*/
	addis	r1, r0, _stack_addr@ha
	addi	r1, r1, _stack_addr@l
    mtlr    r0

	blr
}

/***************************************************************************/
/*
 *	__init_data
 *
 *	Initialize all (RAM) data sections, copying ROM sections as necessary.
 *
 *	dst			destination RAM address
 *	size		number of bytes to zero
 *
 *	we now overload the function in the event that the user wants pic pid
 *
 */
/***************************************************************************/
extern void __init_data(void)
{
	__pic_rom_copy_info *dci;
	__pic_bss_init_info *bii;
	int					delta = __get_runtime_linktime_delta();
	unsigned int		size;
	unsigned char 		*ram_addr;		/* address in ram (executing address) */
	unsigned char 		*ram_end;		/* end address in ram (executing address) */
	unsigned char 		*rom_addr;		/* address in rom */
	unsigned char 		*rom_end;		/* end address in rom */
	int					internal;
		
	/* for sda pic pid, if ram_end and ram_addr are swapped so that ram_end < ram_addr, 		*/
	/* then segment is internal, otherwise it is external.  for eabi, addresses are external 	*/

	dci = _pic_rom_copy_info;
	while (1) {
		if (dci->rom_addr == 0 && dci->ram_addr == 0 && dci->ram_end == 0) break;
		internal = (dci->rom_end < dci->rom_addr);
		if (internal) {
			rom_addr = dci->rom_end + delta;
			rom_end = dci->rom_addr + delta;
		} else {
			rom_addr = dci->rom_addr;
			rom_end = dci->rom_end;
		}
		internal = (dci->ram_end < dci->ram_addr);
		if (internal) {
			ram_addr = dci->ram_end + delta;
			ram_end = dci->ram_addr + delta;
		} else {
			ram_addr = dci->ram_addr;
			ram_end = dci->ram_end;
		}
		size = (unsigned int) (ram_end - ram_addr);
 		__copy_rom_section(ram_addr, rom_addr, size);
 		dci++;
	}
 
 	/* Initialize with zeros: */

	bii = _pic_bss_init_info;
	while (1) {
		if (bii->ram_addr == 0 && bii->ram_end == 0) break;
		internal = (bii->ram_end < bii->ram_addr);
		if (internal) {
			ram_addr = bii->ram_end + delta;
			ram_end = bii->ram_addr + delta;
		} else {
			ram_addr = bii->ram_addr;
			ram_end = bii->ram_end;
		}
		size = (unsigned int) (ram_end - ram_addr);
 		__init_bss_section(ram_addr, size);
 		bii++;
	}
	
	/* now that data is copied to ram, we can fix up initialized pointers */
	__mwerks_fixup_relocations();	
}

/***************************************************************************/
/*
 *	__exception_info_constants
 *
 *	Called from __init_cpp_exceptions.cpp
 *
 *	info		address of linker generated exception table info
 *	R2			address of variable to hold the value in r2
 *
 *	we now overload the function in the event that the user wants pic pid
 *
 */
/***************************************************************************/
extern void __exception_info_constants(void **info, char **R2)
{
	register char *temp;				/* r2 register contents								*/

	asm {
		mr      temp,r2
	}
	*R2 = temp;
	
	*info = _pic_eti_init_info;
}

/***************************************************************************/
/*
 *	__find_exception_addresses
 *
 *	Called from ExceptionPPC.cp
 *
 *	info		address of linker generated exception table info
 *	returnaddr	address within a code segment
 *	returnaddr	address within a code segment
 *	ex_start	address of variable to hold address of exception table info
 *	ex_end		address of variable to hold end address of exception table info
 *
 *	we now overload the function in the event that the user wants pic pid
 *
 */
/***************************************************************************/
extern int __find_exception_addresses(void *info, char *returnaddr, void **ex_start, void **ex_end)
{
	__pic_eti_init_info	*eti_info = (__pic_eti_init_info*)info;
	unsigned char		*start;			/* address */
	unsigned char		*end;			/* end address */
	int					internal;
	int					delta = __get_runtime_linktime_delta();
	
	while (1) {
		if (eti_info->code_end - eti_info->code_start == 0) break;
		internal = (eti_info->code_end < eti_info->code_start);
		if (internal) {
			start = eti_info->code_end + delta;
			end = eti_info->code_start + delta;
		} else {
			start = eti_info->code_start;
			end = eti_info->code_end;
		}
		if((unsigned char*)returnaddr>=start && (unsigned char*)returnaddr<end) {
			internal = (eti_info->eti_end < eti_info->eti_start);
			if (internal) {
				start = eti_info->eti_end + delta;
				end = eti_info->eti_start + delta;
			} else {
				start = eti_info->eti_start;
				end = eti_info->eti_end;
			}
			*ex_start = start;
			*ex_end = end;
			return(1);
		}
 		eti_info++;
	}
	
	return(0);
}


#endif
