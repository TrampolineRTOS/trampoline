/*
 * Static internal receiving unqueued message object $MESSAGE_NAME$
 */

tpl_com_data $BUFFER$[$SIZE$];

tpl_internal_receiving_unqueued_mo $MESSAGE$ = {
    {   /* data receiving mo struct     */
        {   /* base receiving mo struct */
            /* notification pointer     */  $NOTIFICATION_PTR$,
            /*  next receiving mo       */  (tpl_base_receiving_mo *)$TARGET$
        },
        /*  receiving function      */  (tpl_receiving_func)tpl_receive_static_internal_unqueued_message,
        /*  copy function           */  (tpl_data_copy_func)tpl_copy_from_unqueued,
        /*  filter pointer          */  $FILTER$
    },
    /*  buffer  */  $BUFFER$,
    /*  size    */  $SIZE$
};
