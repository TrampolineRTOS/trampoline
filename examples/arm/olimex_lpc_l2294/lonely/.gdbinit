target remote localhost:3333
monitor arm7_9 force_hw_bkpts enable
monitor reset halt
monitor mww 0xE002C014 0x0F804924
monitor mdw 0xE002C014
monitor mww 0xFFE00004 0x20000400
monitor mdw 0xFFE00004
directory lonely /Users/DavidGarriou/GitHub/trampoline/os /Users/DavidGarriou/GitHub/trampoline/machines/arm /Users/DavidGarriou/GitHub/trampoline/machines/arm/olimex_lpc_l2294 /Users/DavidGarriou/GitHub/trampoline/machines/arm/olimex_lpc_l2294/drivers .
file lonely_exe
load
monitor mww 0xE01FC040 2
monitor mdw 0xE01FC040
monitor soft_reset_halt
display/i $pc
display/x $sp
