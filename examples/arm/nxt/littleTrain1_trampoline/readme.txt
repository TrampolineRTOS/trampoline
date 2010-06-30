TODO : Reverse bluetooth driver made by nxtosek. I thought it should be better to rewrite in bt_frame[] each frame received but it could generates errors if the values received frequency in higher than the value read frequency !!!


THE APPLICATION:
The application is a robot little train.
Thanks to the java software, commands are sent to the first robot (to command it). When moving, it sends its movement vector to the other robots (one for now) which follow him (in theory...).
This is the first robot.

This application of three tasks :
- task_idle which launch the bluetooth connexion before shutdown itself
- Odometry which find the robot position according to its movement.
- Send which sends its movement by bluetooth to the other robots (by the computer).
- The ISR2 controls the direction according to the value received by bluetooth.

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
