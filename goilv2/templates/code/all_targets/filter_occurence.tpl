/*
 * $FILTER_KIND$ filter of message object $MESSAGE_NAME$
 */
 
tpl_com_count occ = 0;

tpl_occurence_filter_desc $FILTER$ = {
    {
    /*  filtering function          */  $FILTERING_FUNC$
    },
    /*  period                      */  $PERIOD$-1,
    /*  offset 						*/	$OFFSET$,
    /*  occurence pointer           */  &occ
};

