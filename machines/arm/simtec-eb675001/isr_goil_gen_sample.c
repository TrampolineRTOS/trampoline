#include "interruptions_parametres_possibles.h"

/*
 Configuration OIL correspondante :

ISR sample_isr = {
	SOURCE = TIMER4;
	PRIORITY = 4;
	CATEGORY = 2; // <=> catégorie OSEK ??
};

*/

#define sample_isr_id 3

/* TODO : protection mémoire : être en mesure de
 * générer des catégories de mémoire associées à chaque
 * ISR. En somme, il faudra remplacer OS_APP_DATA
 * par quelque chose du genre SAMPLE_ISR_STACK, permettant
 * de préciser à l'infrastructure protection mémoire (via MemMap)
 * que cette variable appartient à la zone de pile de
 * l'ISR "sample_isr". 
 *
 * La valeur XXX est soit :
 * - la valeur par défaut définie dans le fichier OIL
 * - la valeur précisée dans le fichier OIL pour cette ISR
 *   (définir la syntaxe) */
VAR(tpl_stack_word, OS_APP_DATA) sample_isr_stack[XXX];

FUNC(void, OS_CODE) sample_isr_function (void);

VAR(arm_context, OS_VAR) sample_isr_core_context;

CONST(tpl_proc_static, OS_CONST) sample_isr_stat_desc = {
	&sample_isr_core_context,
	sample_isr_stack,
	sample_isr_function,
	NULL,
	sample_isr_id,
#ifdef WITH_OSAPPLICATION
	$APP_ID$,
#endif
	(tpl_priority)4,
	1,
	IS_ROUTINE,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
	NULL
#endif
};


tpl_isr_static sample_isr_isr_helper = {
	NULL, /* helper */
	NULL, /* next */
	sample_isr_id
};

VAR(tpl_proc, OS_VAR) sample_isr_desc = {
	/* resources */ 		NULL,
	/* activate count */		0,
	/* isr priority */		(tpl_priority)4,
	/* isr state */			SUSPENDED
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
	, TRUE /* TODO: double emploi avec enable_isr ? (cf AUTOSAR) */
#endif
};

VAR(tpl_oki_interrupt_source_type, OS_VAR) sources_for_isr_id[] = {
	INTERRUPTION_TIMER_4
};

CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1] = {
	&sample_isr_stat_desc
};

CONSTP2CONST(tpl_proc, AUTOMATIC, OS_APPL_DATA)
tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1] = {
	&sample_isr_desc
};

#if ISR_COUNT > 0
CONSTP2CONST(tpl_isr_static, AUTOMATIC, OS_APPL_DATA)
tpl_isr_stat_table[ISR_COUNT] = {
	&sample_isr_isr_helper
}
#endif

#ifdef WITH_AUTOSAR
VAR(tpl_isr2_enable_state, OS_VAR)
tpl_isr2_enable_table[ISR_COUNT] = {
	ENABLED
};
#endif /* WITH_AUTOSAR */

#endif /* ISR_COUNT */
