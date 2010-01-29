target remote localhost:3333
monitor wait_halt
monitor mww 0xE01FC040 0
monitor mdw 0xE01FC040
monitor load_image lonely_exe
monitor mww 0xE01FC040 2
monitor mdw 0xE01FC040
monitor soft_reset_halt
monitor resume
