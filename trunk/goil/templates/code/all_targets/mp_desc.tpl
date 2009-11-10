CONST(tpl_mem_prot_desc, OS_CONST) $NAME$_mp_desc = {
  { /* proc_var memory region */
    &__SEG_START_TASK_$NAME$_VAR_RGN,
    &__SEG_END_TASK_$NAME_VAR_RGN
  },
  { /* proc_stack memory region */
    &__SEG_START_TASK_$NAME$_STACK_RGN,
    &__SEG_END_TASK_$NAME$_STACK_RGN
  }
#ifdef WITH_AUTOSAR
  ,{ /* osap_var memory region */
    &__SEG_START_APP_$NAME$_VAR_RGN,
    &__SEG_END_APP_$NAME$_VAR_RGN
  }
};
