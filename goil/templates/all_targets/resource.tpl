/*
 * Resource descriptor of resource $RESOURCE_NAME$
 *
 * Tasks which use this resource :
 * $TASKS$
 *
 * ISRs which use this resource :
 * $ISRS$
 */
tpl_resource $RESOURCE$ = {
    /* ceiling priority of the resource */  (tpl_priority)$PRIORITY$,
    /* owner previous priority          */  (tpl_priority)0,
    /* owner of the resource            */  NULL,
    /* next resource in the list        */  NULL
};

