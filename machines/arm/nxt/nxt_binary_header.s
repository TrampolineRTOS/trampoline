/*
   nxt_binary_header.s

   This assembly code is used for executing a nxtOSEK
   application in John Hansen's enhanced NXT standard firmare
   and this approach is developed by Sivan Toledo.
   Takashi Chikamasa, May 2008

   Sivan Toledo, May 2008
   to enable calling a native AT91SAM7 program 
   from the NXT's firmware, using a modification
   implemented by John Hansen.
   
   The NXT firmware recognizes a native file by the
   string "NXTBINARY" at the beginning of the file.
   To keep the changes in the NXT's firmware minimal,
   the file name must be .rxe (same as the stadard
   NXT binaries which are for a virtual machine).
   
   When the NXT's firmware recognizes a native file,
   it calls a function at offset X in the file, where
   X is the 32-bit number stored in offset 12 in the file.
   The firmware passes two arguments to the function: the 
   address of the file in flash, and the length of the file. 

    The code in this file uses the arguments (location and size
    of the native file) to relocate the file (except for the first 16
    bytes, which are a header) to the beginning of RAM, initialize
    the AT91SAM7S, and initialize the C environment (stack and variables
    that initialized to zero).
*/

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.extern NXT_Entry_Point

	.text
	.code 32
	.align 	0
	
/*
 * NXT's enhanced firmware recognizes this marker to execute a file without
 * VM (native execution)
 */
NXT_Binary_Header:
     /* Marker for standard firmware. */
	.ascii "NXTBINARY\0\0\0"

	/* Address offset to jump to NXT_Entry_Point(RAM copier) */
	.word  NXT_Entry_Point - NXT_Binary_Header - 4


