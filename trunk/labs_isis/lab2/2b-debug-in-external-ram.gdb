target remote localhost:3333
monitor arm7_9 force_hw_bkpts enable
monitor reset halt
monitor mww 0xE002C014 0x0F804924
monitor mdw 0xE002C014
monitor mww 0xFFE00004 0x20000400
monitor mdw 0xFFE00004
file lab2_exe
load
directory lonely . ../../os ../../machines/arm/olimex_lpc_h2294
monitor mww 0xE01FC040 2
monitor mdw 0xE01FC040
monitor soft_reset_halt
display/i $pc
display/x $sp
