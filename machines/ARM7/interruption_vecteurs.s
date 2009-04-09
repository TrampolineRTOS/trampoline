
/* ---------------------------------------------------------------------------- *
 * Section des vecteurs d'exception
 * ---------------------------------------------------------------------------- */
 
	.section .vectbl
 
	.align 2

	.global Vec_reset
	
	.xref start
	
Vec_reset:			         b start
Vec_undefinedInstruction:	b Interruption_gestionnaire_undef
Vec_softwareInterrupt:		b Interruption_gestionnaire_swi
Vec_prefetchAbort:		   b Interruption_gestionnaire_pfabort
Vec_dataAbort:			      b Interruption_gestionnaire_dabort
Vec_unused:			        b Interruption_gestionnaire_unused
Vec_interruptRequest:		b Interruption_gestionnaire_principal_irq
Vec_fastInterruptRequest:	b Interruption_gestionnaire_principal_fiq
 
/* ---------------------------------------------------------------------------- *
 * Section de programme
 * ---------------------------------------------------------------------------- */
 
   .text

	.align 2

/* Ce sous-programme délègue le traitement des demandes d'interruptions
 * logicielles à une fonction écrite en C */

Interruption_gestionnaire_swi:
   /* Il ne s'agit pas d'une sauvegarde de registres, mais d'une mise
    * à disposition de leurs valeurs pour le gestionnaire */
   stmfd sp!, {r0-r12, lr}

   /* Récupération du numéro du service demandé.
    * Connaissant l'adresse de retour, on analyse le code de l'instruction SWI
    * qui a été exécutée. Le numéro est disposé sur les 24 bits de poids faible */
   ldr r0, [lr, #-4]
   bic r0, r0, #0xFF000000

   /* On fournit au gestionnaire un pointeur vers les registres empilés,
    * c'est-à-dire un moyen d'accéder aux paramètres passés par registres
    * à l'instruction SWI */
   mov r1, sp

   /* En cas d'exécutions imbriquées de l'instruction SWI, il faut sauvegarder
    * les indicateurs d'état de SPSR dans la pile */
   mrs r2, spsr
   stmfd sp!, {r2}

   /* Déléguer le traitement */
   bl Interruption_gestionnaire_principal_swi
   /* Ici, le gestionnaire a retourné son résultat dans R0 */

   /* Restaurer les indicateurs d'état de SPSR */
   ldmfd sp!, {r2}
   msr spsr_cxsf, r2

   /* Retourner à l'appelant sans restaurer R0 */
   ldmed sp!, {r1-r12, pc}^

/* Les autres exceptions ne font pas l'objet d'un traitement particulier :
 * on provoque la fin du programme en forçant un point d'arrêt et on bloque
 * le processeur dans une boucle infinie vide.
 *
 * La valeur 0xDFFFDFFF est reconnue par le BDI2000 comme un point d'arrêt GDB.
 * Cette valeur ne donnera pas le résultat escompté si le système n'est pas
 * contrôlé par le BDI2000. */

Interruption_gestionnaire_undef:
   .word 0xDFFFDFFF
   b .

Interruption_gestionnaire_pfabort:
   .word 0xDFFFDFFF
   b .

Interruption_gestionnaire_dabort:
   .word 0xDFFFDFFF
   b .

Interruption_gestionnaire_unused:
   .word 0xDFFFDFFF
   b .
   

