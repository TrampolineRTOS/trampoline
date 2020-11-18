tar extended-remote :4242
load
break ShutdownOS
cont
dump memory dump.mem &(tpl_trace_queue[0]) &(tpl_trace_queue[499])
quit
