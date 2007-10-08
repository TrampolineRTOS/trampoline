/*
 * Timing protection descriptor for $NAME$
 */
$LOCK_TIME_TABLE$
 
tpl_timing_protection $TIMING_PROT$ = {
    /* execution budget/time    */  $EXE_BUDGET$,
    /* time limit               */  $COUNT_LIMIT$,
    /* time frame               */  $TIME_FRAME$,
    /* resource lock time       */  $REZ_LOCK_TIME$,
    /* os interrupt lock time   */  $OS_IT_LOCK$,
    /* all interrupt lock time  */  $ALL_IT_LOCK$
};

