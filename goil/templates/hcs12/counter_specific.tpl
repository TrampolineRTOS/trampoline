
void tpl_schedule(int from);
tpl_status tpl_counter_tick(tpl_counter *counter);

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$
	if (need_rescheduling == NEED_RESCHEDULING) {
		tpl_schedule(FROM_IT_LEVEL);
    }
}

