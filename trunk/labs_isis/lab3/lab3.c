FUNC(void, OS_CODE) displayIdAndCurrentPriority()
{
  TaskType id;
  GetTaskID(&id);
  if (id >= 0)
  {
    tpl_priority prio = tpl_dyn_proc_table[id]->priority;
    lcd_print_char(’:’);
    lcd_print_unsigned(id);
    lcd_print_char(’,’);
    lcd_print_unsigned(prio);
  }
}