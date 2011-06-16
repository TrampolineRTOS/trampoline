
/*
 * Reading and Resetting macros for flag $FLAGNAME$
 */

#define ReadFlag_$FLAGNAME$() \
    (FlagValue)$FLAG_READ_EXP$
    
#define ResetFlag_$FLAGNAME$() \
    $FLAG_RESET_EXP$
