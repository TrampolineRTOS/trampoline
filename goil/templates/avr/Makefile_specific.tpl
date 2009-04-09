#add the 'hex' rule for avr
hex: $APP_NAME$
	avr-objcopy -j .text -j .data -O ihex $APP_NAME$ $APP_NAME$.hex

EXTRA_FILES_MRPROPER += $APP_NAME$ $APP_NAME$.hex
