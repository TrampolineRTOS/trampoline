/*
 * Resource descriptor of internal resource $RESOURCE_NAME$
 *
 * Tasks which use this resource :
 * $TASKS$
 *
 */
tpl_internal_resource $RESOURCE$ = {
    /* ceiling priority of the resource */  (tpl_priority)$PRIORITY$,
    /* owner previous priority          */  (tpl_priority)0,
    /* true if the resource is taken    */  FALSE
};
