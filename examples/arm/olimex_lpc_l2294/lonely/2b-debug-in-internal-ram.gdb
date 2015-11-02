target remote localhost:3333
monitor arm7_9 force_hw_bkpts enable
monitor wait_halt
monitor mww 0xE01FC040 2
monitor mdw 0xE01FC040
directory lonely /Users/DavidGarriou/GitHub/trampoline/os /Users/DavidGarriou/GitHub/trampoline/machines/arm /Users/DavidGarriou/GitHub/trampoline/machines/arm/olimex_lpc_l2294 /Users/DavidGarriou/GitHub/trampoline/machines/arm/olimex_lpc_l2294/drivers .
file lonely_exe
load
monitor soft_reset_halt
