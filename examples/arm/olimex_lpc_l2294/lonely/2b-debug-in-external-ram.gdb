target remote localhost:3333
monitor gdb_breakpoint_override hard
monitor reset halt
monitor mww 0xE002C014 0x0F804924
monitor mdw 0xE002C014
monitor mww 0xFFE00004 0x20000400
monitor mdw 0xFFE00004
file lonely_exe
load
directory lonely /Users/DavidGarriou/GitHub/trampoline/os /Users/DavidGarriou/GitHub/trampoline/machines/arm /Users/DavidGarriou/GitHub/trampoline/machines/arm/olimex_lpc_l2294 /Users/DavidGarriou/GitHub/trampoline/machines/arm/olimex_lpc_l2294/drivers .
monitor mww 0xE01FC040 2
monitor mdw 0xE01FC040
monitor soft_reset_halt
display/i $pc
display/x $sp
display tpl_kern
