target remote localhost:3333
monitor wait_halt
monitor mww 0xE01FC040 0
monitor mdw 0xE01FC040
monitor mww 0xE002C014 0x0F804924
monitor mdw 0xE002C014
monitor mww 0xFFE00004 0x20000400
monitor mdw 0xFFE00004
monitor load_image lonely_exe
monitor mww 0xE01FC040 2
monitor mdw 0xE01FC040
monitor soft_reset_halt
monitor resume
