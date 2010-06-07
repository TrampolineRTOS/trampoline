THE APPLICATION:
This example is for a robot-car, made of 4 wheels (the 2 rear wheels are commanded by 2 motors). Another motor (motorC) set the direction. Set an angle to turn (between -50° and 50°). To turn left, set a motorC speed positive. To turn right, set a motorC speed negative. The stop button shutdowns the Trampoline application.
 
IMPORTANT:
Even if you don't need alarms, you have to connect the SystemCounter to it_timer1 source. It will check the buttons status every 100ms and you'll be able to connect ISRs (it's temporary).
If you'ld like to connect ISRs to a device, use the source name in goil/templates/config/arm/nxt/target.cfg like the four ISR2 already connected.
Whatever ISR you'ld like to add (ISR1 or ISR2) with the name isr_button_start, you have to add the function "ISR(isr_button_start)" in your files (including tpl_os_definition.h).
 
GET STARTED:
Get started with the documentation in documentation/getstarted/getstarted.pdf

DRIVERS:
The bluetooth driver has been modified from the Lejos driver. To receive datas from the bluetooth, add an ISR2 with "it_bluetooth" as source in your oil file.
Because the ISR2 is launched twice per frame (once after the length of the datas and once at the end of the frame), you have to add inyour C file :
" extern u8 bt_frame[128]; extern boolean bt_frame_received; "
and in your ISR2 :
" if(bt_frame_received == TRUE) { //insert your code to analyse datas wich are in bt_frame[] } "
