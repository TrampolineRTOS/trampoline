/*
 * Fichier : startup.s
 *
 * Programme de démarrage de l'application.
 *
 * Ce module prend en charge les points suivants :
 *   - définition du vecteur 0 pour le démarrage du programme au reset du processeur
 *   - allocation d'une zone de pile et initialisation du pointeur de pile
 *   - appel de la fonction main
 *   - blocage du processeur aprÃ¨s le retour de main
 *
 * $Date: 2008/05/20 12:09:34 $
 * $Rev$
 * $Author: GuillaumeNuth $
 * $URL$
 */
 
/* ---------------------------------------------------------------------------- *
 * Constantes symboliques
 * ---------------------------------------------------------------------------- */
 
.set CPSR_SVC, 0xd3
.set CPSR_IRQ, 0xd2
.set CPSR_FIQ, 0xd1
.set CPSR_USR, 0xd0

/* ---------------------------------------------------------------------------- *
 * Section de programme
 * ---------------------------------------------------------------------------- */
 
	.text
 
/* L'étiquette start désigne le point d'entrée du programme.
 *
 * Le but de ce programme de démarrage est d'effectuer les initialisations
 * nécessaires au bon déroulement de l'application.*/
 
	.align 2
 
   .global start

start:

	

	/* Initialisation du pointeur de pile en mode IRQ */
    msr cpsr_c, #CPSR_IRQ
	ldr sp, =irq_stack_bottom
 	
	/* Initialisation du pointeur de pile en mode FIQ */
    msr cpsr_c, #CPSR_FIQ
	ldr sp, =fiq_stack_bottom
 	
	/* Initialisation du pointeur de pile en mode superviseur */
/*    msr cpsr_c, #CPSR_SVC
	ldr sp, =svc_stack_bottom*/
 	
 	/* Initialisation du pointeur de pile en mode USR */
  	msr cpsr_c, #CPSR_USR
	ldr sp, =svc_stack_bottom

    bl Memoire_initialiser
    bl main
 
		/* Blocage du processeur dans une boucle infinie vide */
forever:
	b forever
	
	
/* La valeur 0xDFFFDFFF est reconnue par le BDI2000 comme un point d'arrêt GDB.
 * Cette valeur ne donnera pas le résultat escompté si le système n'est pas
 * controlé par le BDI2000. */

Startup_fin:
   .word 0xDFFFDFFF

	/* Blocage du processeur dans une boucle infinie vide */
	b .

