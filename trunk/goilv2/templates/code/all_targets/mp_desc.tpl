extern void *__SEG_START_Task_$NAME$_VAR_RGN;
extern void *__SEG_END_Task_$NAME$_VAR_RGN;
extern void *__SEG_START_Task_$NAME$_STACK_RGN;
extern void *__SEG_END_Task_$NAME$_STACK_RGN;

CONST(tpl_mem_prot_desc, OS_CONST) $NAME$_mp_desc = {
  { /* proc_var memory region */
    &__SEG_START_Task_$NAME$_VAR_RGN,
    &__SEG_END_Task_$NAME$_VAR_RGN
  },
  { /* proc_stack memory region */
    &__SEG_START_Task_$NAME$_STACK_RGN,
    &__SEG_END_Task_$NAME$_STACK_RGN
  }
#ifdef WITH_AUTOSAR
  ,{ /* osap_var memory region */
    &__SEG_START_APP_$APP_NAME$_VAR_RGN,
    &__SEG_END_APP_$APP_NAME$_VAR_RGN
  }
#endif
};
