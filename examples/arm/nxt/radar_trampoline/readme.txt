THE APPLICATION:
This example is for a robot-car. The motor A is here for the speed, it drives the two rear wheels (between -100 and +100). The  motor C is here for the direction, it turns the 2 front wheels (with an angle between -40¡ and +40¡). The motor B is here for the radar, it rotates the ultrasonic sensor to be able to draw a near filed map. The main part comes from the "NXT GT" example from the NXTOSEK website (http://lejos-osek.sourceforge.net/nxtgt.htm) (except for the two rears wheels).

This application of three tasks :
- task_idle which launch the bluetooth connexion before shutdown itself
- task_command_motors which controls the direction according to the value received by bluetooth by the ISR2.
- task_send_bt which drive the radar motor and send the ultrasonic sensor value by bluetooth to the computer.
 
The "stop button" (the dark grey button on the face of the NXT brick) shutdowns the Trampoline application.
 
GET STARTED:
Get started with the documentation in documentation/getstarted/getstarted.pdf

IMPORTANT:
Even if you don't need alarms, you have to connect the SystemCounter to it_timer1 source. It will check the buttons status every 100ms and you'll be able to connect ISRs (it's temporary).
If you'ld like to connect ISRs to a device, use the source name in goil/templates/config/arm/nxt/target.cfg like the four ISR2 already connected.
Whatever ISR you'ld like to add (ISR1 or ISR2) with the name X, you have to add the function "ISR(X)" in your files.
 
DRIVERS:
The bluetooth driver has been modified from the Lejos driver. To receive datas from the bluetooth, add an ISR2 with "it_bluetooth" as source in your oil file.
Because the ISR2 is launched twice per frame (once after the length of the datas and once at the end of the frame), you have to add inyour C file :
" extern u8 bt_frame[128]; extern boolean bt_frame_received; "
and in your ISR2 :
" if(bt_frame_received == TRUE) { //insert your code to analyse datas wich are in bt_frame[] } "
