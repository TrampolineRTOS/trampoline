/*
 * Static internal receiving queued message object $MESSAGE_NAME$
 */

tpl_com_data $BUFFER$[$QUEUE_SIZE$*$ELEMENT_SIZE$];

tpl_queue_dyn $DYN_QUEUE$ = {
    /*  pointer to the last written element */  NULL,
    /*  current size of the queue           */  0,
    /*  read index                          */  0,
    /*  overflow flag                       */  FALSE
};

tpl_internal_receiving_queued_mo $MESSAGE$ = {
    {   /* data receiving mo struct     */
        {   /* base receiving mo struct */
            /* notification pointer     */  $NOTIFICATION_PTR$,
            /* next receiving mo        */  (tpl_base_receiving_mo *)$TARGET$
        },
        /*  receiving function      */  (tpl_receiving_func)tpl_receive_static_internal_unqueued_message,
        /*  copy function           */  (tpl_data_copy_func)tpl_copy_from_unqueued,
        /*  filter pointer          */  (tpl_filter_desc *)$FILTER_PTR$
    },
    {   /*  queue structure   */
        /*  pointer to the dynamic descriptor   */  &$DYN_QUEUE$,
        /*  max size of the queue               */  $QUEUE_SIZE$,
        /*  element size of the queue           */  $ELEMENT_SIZE$,
        /*  pointer to the buffer               */  $BUFFER$
    }
};
