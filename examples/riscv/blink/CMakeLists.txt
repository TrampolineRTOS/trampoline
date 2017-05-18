add_subdirectory(blink)

set(SOURCE_FILES blink.c)
add_trampoline(blink blinkheader "${SOURCE_FILES}")
