/*
 * $FILTER_KIND$ filter of message object $MESSAGE_NAME$
 */
 
tpl_com_count $OCCURENCE$;

tpl_occurence_filter_desc $FILTER$ = {
    {
    /*  filtering function          */  $FILTERING_FUNC$
    },
    /*  period                      */  $PERIOD$,
    /*  occurence pointer           */  &$OCCURENCE$
};

