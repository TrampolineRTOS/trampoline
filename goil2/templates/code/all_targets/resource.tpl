/*
 * Resource descriptor of resource $RESOURCE_NAME$
 *
 * Tasks which use this resource :
 * $TASKS$
 *
 * ISRs which use this resource :
 * $ISRS$
 */
VAR(tpl_resource, OS_VAR) $RESOURCE$ = {
  /* ceiling priority of the resource */  (tpl_priority)$PRIORITY$,
  /* owner previous priority          */  (tpl_priority)0,
  /* owner of the resource            */  -1,
#ifdef WITH_OSAPPLICATION
  /* OS Application id                */  $APP_ID$,
#endif    
  /* next resource in the list        */  NULL
};

