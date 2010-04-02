THE APPLICATION:
This example is for a robot-car, made of 4 wheels (the 2 rear wheels are commanded by 2 motors). Another motor (motorC) set the direction. Set an angle to turn (between -50° and 50°). To turn left, set a motorC speed positive. To turn right, set a motorC speed negative. The stop button shutdowns the Trampoline application.
 
IMPORTANT:
Even if you don't need alarms, you have to connect the SystemCounter to it_timer1 source. It will check the buttons status every 100ms and you'll be able to connect ISRs (it's temporary).
If you'ld like to connect ISRs to a device, use the source name in goil/templates/config/arm/nxt/target.cfg like the four ISR2 already connected.
Whatever ISR you'ld like to add (ISR1 or ISR2) with the name isr_button_start, you have to add the function "ISR(isr_button_start)" in your files (including tpl_os_definition.h).
 
GET STARTED:
Get started with the documentation in documentation/getstarted/getstarted.pdf
