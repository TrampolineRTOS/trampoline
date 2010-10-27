/*----------------------------------------------------------------------------
 * Name:    Startup.c
 * Purpose: Routine d'init pour initialiser stack et variables initialisée
 * Version: V1.00
 *----------------------------------------------------------------------------
 * SDM [28 Juillet 2009] création et test en simulé 
 *     testé sous GCC 
 *----------------------------------------------------------------------------*/
	
	.section ".text"
	.align	2

	.global	Startup
	.type	Startup, %function

Startup:
/* Initialisation de la stack */
	LDR	 	R0, Startup_constants+12
	MOV		SP, R0

/* 
 * Initialisation à des variables initialisées 
 * R0: @Destination, R1: @Source, R2: taille, R3: compteur, R4: temp
 */
debut_init_ram:
	LDR		R0, Startup_constants+16
	LDR		R1, Startup_constants+20
	LDR		R2, Startup_constants+24
	MOV		R3, #0
boucle_init_ram:
	CMP		R3, R2
	BCS		debut_zero_ram
    LDR		R4,[R1,#0]
	STR		R4,[R0,#0]
	ADD		R3, #4
	ADD		R1, #4
	ADD		R0, #4
	B		boucle_init_ram

/* 
 * Initialisation à zero des variables non initialisées 
 * R0: @Destination, R2: taille, R3: compteur, R4: temp
 */
debut_zero_ram:
	LDR		R0, Startup_constants+0
	LDR		R2, Startup_constants+8
	MOV		R3, #0
	MOV		R4, #0
boucle_zero_ram:
	CMP		R3, R2
	BCS		appel_main
	STR		R4,[R0,#0]
	ADD		R3, #4
	ADD		R0, #4
	B		boucle_zero_ram

/* 
 * Fin de la routine d'init, appel du main 
 */
appel_main:
	BL		main

/*
 * Constantes utilisées par Startup		
 * Stockées en section .text, après la routine
 */
	/* .align	2 inutile, normalement */
	.section ".text"	
Startup_constants:
	.word	__cs3_region_start_bss
	.word	__cs3_region_zero_ram_loadaddr
	.word	__cs3_region_zero_ram_size
	.word	__cs3_stack
	.word	__cs3_region_start_data
	.word	__cs3_region_init_ram_loadaddr
	.word   __cs3_region_init_ram_size
	
	.end
