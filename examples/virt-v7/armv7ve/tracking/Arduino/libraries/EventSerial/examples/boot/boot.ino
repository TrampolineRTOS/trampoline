#include <EventSerial.h>

#define MSG_RX_XVISOR_PROMPT           "XVisor#"
#define MSG_RX_UBOOT_PROMPT            "U-Boot>"

void ubootEventFunction(EventSerialManager &manager) {
  HardwareSerial &serial = manager.Serial3();
  serial.println("ubootEventFunction");
}

void xvisorEventFunction(EventSerialManager &manager) {
  HardwareSerial &serial = manager.Serial3();
  serial.println("xvisorEventFunction");
}

EventSerial ubootEvt(MSG_RX_UBOOT_PROMPT, ubootEventFunction);
EventSerial xvisorEvt(MSG_RX_XVISOR_PROMPT, xvisorEventFunction);

EventSerialManager serial3Mgr(Serial3);

void setup() {
  serial3Mgr.addEvent(ubootEvt);
  serial3Mgr.addEvent(xvisorEvt);

}

void loop() {
  serial3Mgr.execute();
}
