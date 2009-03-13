/*
 * $FILTER_KIND$ filter of message object $MESSAGE_NAME$
 */
 
char occ$INITIALVALUE$-$PERIOD$+1;

tpl_occurence_filter_desc $FILTER$ = {
    {
    /*  filtering function          */  $FILTERING_FUNC$
    },
    /*  period                      */  $PERIOD$,
    /*  offset 						*/	$OFFSET$,
    /*  occurence pointer           */  &occ
};

