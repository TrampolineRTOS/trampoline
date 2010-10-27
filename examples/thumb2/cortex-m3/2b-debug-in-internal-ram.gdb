target remote localhost:3333
monitor arm7_9 force_hw_bkpts enable
monitor wait_halt
monitor mww 0xE01FC040 2
monitor mdw 0xE01FC040
file lonely_exe
load
directory sources /usr/local/arm-dev-files/sources
monitor soft_reset_halt
