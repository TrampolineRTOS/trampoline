/*
 * FILE : MPC567xF_Startup.c
 *	
 * COPYRIGHT (c) 2007-2012 Freescale Semiconductor, Inc. All rights reserved.
 * 	
 * DESCRIPTION: This file contains the application entry point __startup.  
 *  
 * VERSION: 1.2 
 */

#ifdef __cplusplus
extern "C" {
#endif

__declspec(section ".init") extern void __startup(int argc, char **argv, char **envp);
/* primary entry point */
extern void __start(register int argc, register char **argv, register char **envp);

#ifdef __cplusplus
}
#endif

asm void __startup(register int argc, register char **argv, register char **envp)
{
	nofralloc							/* explicitly no stack */
	// call standard application initialization
	bl __start
}
