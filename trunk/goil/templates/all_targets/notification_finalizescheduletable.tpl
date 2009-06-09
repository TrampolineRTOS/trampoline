/*
 * Finalize schedule table notification $NOTIFICATION_NAME$
 */

tpl_schedule_table $SCHEDTABLE$;

tpl_finalize_schedule_table_action $NOTIFICATION$ = {
{
/*  notification function */  tpl_action_finalize_schedule_table
},
/*  Schedule table descriptor pointer              */  &$SCHEDTABLE$
};