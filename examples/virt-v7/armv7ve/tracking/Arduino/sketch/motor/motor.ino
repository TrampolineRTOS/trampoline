#include <EventSerial.h>

#define CR '\n'

#define FSM_AUTOBOOT_INIT         0x10
#define FSM_AUTOBOOT_CANCEL       0x11
void fsm_autoboot(HardwareSerial&);
int fsm_state_autoboot = FSM_AUTOBOOT_INIT;

#define FSM_UBOOT_NA              0x20
#define FSM_UBOOT_INIT            0x21
#define FSM_UBOOT_CANCEL          0x22
void fsm_uboot(HardwareSerial&);
int fsm_state_uboot = FSM_UBOOT_NA;

#define FSM_XVISOR_NA             0x40
#define FSM_XVISOR_INIT           0x41
#define FSM_XVISOR_GUEST_LAUNCHED 0x42
#define FSM_XVISOR_GUEST_VSERIAL  0x43
void fsm_xvisor(HardwareSerial&);
int fsm_state_xvisor = FSM_XVISOR_NA;

#define FSM_TRAMPOLINE_NA         0x80
#define FSM_TRAMPOLINE_INIT       0x81
#define FSM_TRAMPOLINE_RUN        0x82
void fsm_trampoline(HardwareSerial&);
int fsm_state_trampoline = FSM_TRAMPOLINE_NA;

/* ===================================================================
 * Gestionnaire d'évenements sur la ligne série.
 * Les évenements correspondent à l'arrivée d'une chaine de caractères 
 * déterminée à l'avance sur la ligne série.
 */
//#define MSG_RX_AUTOBOOT_PROMPT         "Hit any key to stop autoboot:"
#define MSG_RX_AUTOBOOT_PROMPT         "No ethernet found"
#define MSG_RX_UBOOT_PROMPT            "U-Boot>"
#define MSG_RX_XVISOR_PROMPT           "XVisor#"
#define MSG_RX_TRAMPOLINE_PROMPT       "[guest0/uart0]"
#define MSG_RX_GUEST_LAUNCHED          "guest0: Kicked"
#define MSG_RX_VSERIAL                 "__rien__"
//#define MSG_RX_VSERIAL                 "[guest0/uart0]"

#define MSG_TX_CANCEL_AUTOBOOT         "0"
#define MSG_TX_LAUNCH_XVISOR           "run bootv"
#define MSG_TX_LAUNCH_XVISOR_GUEST     "guest kick guest0"
#define MSG_TX_SWITCH_XVISOR_VSERIAL   "vserial bind guest0/uart0"
#define MSG_TX_LAUNCH_TRAMPOLINE       "startos"

/* Commandes */
#define MSG_RX_REQUETE                 "<requete>"
#define MSG_RXTX_SEPARATEUR            " "
#define MSG_RXTX_FIN                   "\n"
#define MSG_TX_REPONSE                 "<reponse>"

/* convertisseur A/N */
#define MSG_RX_DEMANDE_DE_CONVERSION "analogRead"

/* commande */
#define MSG_RX_ENVOI_POSITION        "digitalWrite"
#define MSG_RX_ENVOI_DIRECTION_HIGH  "HIGH"
#define MSG_RX_ENVOI_DIRECTION_LOW   "LOW"

/* Les ports utilisés */
#define MSG_TXRX_PORT_A0             "A0"
#define MSG_TXRX_PORT_A1             "A1"

/* ===================================================================
 * Configuration pour le DRV8824
 */
const int dirPin   = 44;
const int stepPin  = 45;
const int resetPin = 46;

int delaiInterMicroPas = 18;
int microPasAcceleration = 15;
int microPasDeceleration = 25;
int positionCourante = 0;
int vitesseCourante = 0;
int directionCourante;
 
/* -------------------------------------------------------------------
 * Evenement pour la chaine MSG_RX_AUTOBOOT_PROMPT
 */
void autobootEventFunction(EventSerialManager &manager, byte argCount) {
  HardwareSerial &serial = manager.getSerial();
//  Serial.println("autobootEventFunction");
  fsm_autoboot(serial);
}
EventSerial autobootEvt(MSG_RX_AUTOBOOT_PROMPT, autobootEventFunction);

/* -------------------------------------------------------------------
 * Evenement pour la chaine MSG_RX_UBOOT_PROMPT
 */
void ubootEventFunction(EventSerialManager &manager, byte argCount) {
  HardwareSerial &serial = manager.getSerial();
//  Serial.println("ubootEventFunction");
  fsm_uboot(serial);
}
EventSerial ubootEvt(MSG_RX_UBOOT_PROMPT, ubootEventFunction);

/* -------------------------------------------------------------------
 * Evenement pour la chaine MSG_RX_XVISOR_PROMPT
 */
void xvisorEventFunction(EventSerialManager &manager, byte argCount) {
  HardwareSerial &serial = manager.getSerial();
//  Serial.println("xvisorEventFunction");
  fsm_xvisor(serial);
}
EventSerial xvisorEvt(MSG_RX_XVISOR_PROMPT, xvisorEventFunction);

/* -------------------------------------------------------------------
 * Evenement pour la chaine MSG_RX_GUEST_LAUNCHED
 */
void xvisorGuestLaunchedEventFunction(EventSerialManager &manager, byte argCount) {
  HardwareSerial &serial = manager.getSerial();
//  Serial.println("xvisorGuestLaunchedEventFunction");
  fsm_xvisor(serial);
}
EventSerial xvisorGuestLaunchedEvt(MSG_RX_GUEST_LAUNCHED, xvisorGuestLaunchedEventFunction);

/* -------------------------------------------------------------------
 * Evenement pour la chaine MSG_RX_VSERIAL
 */
void xvisorVserialEventFunction(EventSerialManager &manager, byte argCount) {
  HardwareSerial &serial = manager.getSerial();
//  Serial.println("xvisorVserialEventFunction");
  fsm_xvisor(serial);
}
EventSerial xvisorVserialEvt(MSG_RX_VSERIAL, xvisorVserialEventFunction);

/* -------------------------------------------------------------------
 * Evenement pour la chaine MSG_RX_TRAMPOLINE_PROMPT
 */
void trampolineEventFunction(EventSerialManager &manager, byte argCount) {
  HardwareSerial &serial = manager.getSerial();
  String str = "";
  String args[4];
  
//  Serial.println("trampolineEventFunction");
//  str = "argCount = " + String(argCount);
//  Serial.println(str);
  
  switch (argCount) {
    case 0:
      Serial.println("0 : Nombre d'arguments incorrect");
    break;
    case 1:
      Serial.println("1 : Nombre d'arguments incorrect");
    break;
    case 2:
      if (manager.readString(args[0]) &
          manager.readString(args[1])) {
//        Serial.print("ARGS");Serial.print(":");
//        Serial.print(args[0]);Serial.print(":");Serial.print(String(args[0].length()));Serial.print(":");
//        Serial.print(args[1]);Serial.print(":");Serial.print(String(args[1].length()));Serial.println(":");
        if (args[0].equals(MSG_RX_DEMANDE_DE_CONVERSION)) {
//          Serial.println("Dem conv");
          str = MSG_TX_REPONSE;
          str += MSG_RXTX_SEPARATEUR;
          str += MSG_RX_DEMANDE_DE_CONVERSION;
          str += MSG_RXTX_SEPARATEUR;
          str += args[1];
          str += MSG_RXTX_SEPARATEUR;
//          Serial.println(str);
//          Serial.println(String(args[1].length()));
          if (args[1].equals("A0")) {
//            Serial.println("port A0");
            str += String(analogRead(A0));
          } else if (args[1].equals(MSG_TXRX_PORT_A1)) {
//            Serial.println("port A1");
            str += String(analogRead(A1));
          } else {
            str += "?";
          }
        }
        str += MSG_RXTX_FIN;
        serial.print(str);
//        Serial.print(str);
      } else {
        Serial.print("args[0] : ");
//        Serial.println(args[0]);   
      }
    break;
    case 3:
      int dir;
      if (manager.readString(args[0]) &
          manager.readString(args[1]) &
          manager.readString(args[2])) {
        if (args[0].equals(MSG_RX_ENVOI_POSITION)) {
          str = "[";
          str += args[1];
          str += ":";
          str += args[2];
          if (args[2].equals(MSG_RX_ENVOI_DIRECTION_HIGH)) {
            dir = HIGH;
          } else if (args[2].equals(MSG_RX_ENVOI_DIRECTION_LOW)) {
            dir = LOW;
          } else {
            //TRaiter
          }
          suivre(args[1].toInt(), dir);
        }
        str += "]";
        Serial.println(str);
      }
    break;
    case 4:
      Serial.println("4 : Nombre d'arguments incorrect");
    break;
    default:
      Serial.println("default : Nombre d'arguments incorrect");
    break;
  }  
  fsm_trampoline(serial);
}
EventSerial trampolineEvt(MSG_RX_REQUETE, trampolineEventFunction);

/* -------------------------------------------------------------------
 * Evenement pour la chaine MSG_RX_TRAMPOLINE_RUN
 */
void trampolineRunEventFunction(EventSerialManager &manager, byte argCount) {
  HardwareSerial &serial = manager.getSerial();
//  Serial.println("trampolineRunEventFunction");
  fsm_trampoline(serial);
}
EventSerial trampolineRunEvt(MSG_RX_TRAMPOLINE_PROMPT, trampolineRunEventFunction);

/* -------------------------------------------------------------------
 * Déclaration du manager pour les évenements sur la ligne série
 */
EventSerialManager serial3Mgr(Serial3);

/* ===================================================================
 * Automate
 */
void fsm_autoboot(HardwareSerial &serial) {
  switch (fsm_state_autoboot) {
    case FSM_AUTOBOOT_INIT:
      serial.println(MSG_TX_CANCEL_AUTOBOOT);
      Serial.println(MSG_TX_CANCEL_AUTOBOOT);
      fsm_state_autoboot = FSM_AUTOBOOT_CANCEL;
      fsm_state_uboot = FSM_UBOOT_INIT;
//      Serial.println("FSM_AUTOBOOT_INIT");
    break;
    default:
    break;
  }
}
void fsm_uboot(HardwareSerial &serial) {
  switch (fsm_state_uboot) {
    case FSM_UBOOT_NA:
    break;
    case FSM_UBOOT_INIT:
      serial.println(MSG_TX_LAUNCH_XVISOR);
      Serial.println(MSG_TX_LAUNCH_XVISOR);
      fsm_state_uboot = FSM_UBOOT_CANCEL;
      fsm_state_xvisor = FSM_XVISOR_INIT;
//      Serial.println("FSM_UBOOT_INIT");
    break;
    default:
    break;
  }
}
void fsm_xvisor(HardwareSerial &serial) {
  switch (fsm_state_xvisor) {
    case FSM_XVISOR_NA:
    break;
    case FSM_XVISOR_INIT:
      serial.println(MSG_TX_LAUNCH_XVISOR_GUEST);
//      Serial.println(MSG_TX_LAUNCH_XVISOR_GUEST);
      fsm_state_xvisor = FSM_XVISOR_GUEST_LAUNCHED;
//      Serial.println("FSM_XVISOR_INIT");
    break;
    case FSM_XVISOR_GUEST_LAUNCHED:
      serial.println(MSG_TX_SWITCH_XVISOR_VSERIAL);
//      Serial.println(MSG_TX_SWITCH_XVISOR_VSERIAL);
      fsm_state_xvisor = FSM_XVISOR_NA;
      fsm_state_trampoline = FSM_TRAMPOLINE_INIT;
//      Serial.println("FSM_XVISOR_GUEST_LAUNCHED");
    break;
    case FSM_XVISOR_GUEST_VSERIAL:      
      fsm_state_trampoline = FSM_TRAMPOLINE_INIT;
      fsm_state_xvisor = FSM_XVISOR_NA;
//      Serial.println("FSM_XVISOR_GUEST_VSERIAL");
    break;
    default:
    break;
  }
}
void fsm_trampoline(HardwareSerial &serial) {
  switch (fsm_state_trampoline) {
    case FSM_TRAMPOLINE_NA:
    break;
    case FSM_TRAMPOLINE_INIT:
      serial.println(MSG_TX_LAUNCH_TRAMPOLINE);
//      Serial.println(MSG_TX_LAUNCH_TRAMPOLINE);
      fsm_state_trampoline = FSM_TRAMPOLINE_RUN;
//      Serial.println("FSM_TRAMPOLINE_INIT");
    case FSM_TRAMPOLINE_RUN:
//      Serial.println("FSM_TRAMPOLINE_RUN");
    break;
    break;
    default:
    break;
  }
}

void suivre(int consigneVitesse, int consigneDirection) {
  int dir;
  String str;

  if (consigneVitesse > 0) {
    vitesseCourante = consigneVitesse;
    if (consigneDirection == HIGH) {
      directionCourante = HIGH;
    } else if (consigneDirection == LOW) {
      directionCourante = LOW;
    } else {
      //Probleme
    }
    str = "suivre : " + String(vitesseCourante) + " : " + String(directionCourante);
    Serial.println(str);
    digitalWrite(dirPin, directionCourante); /* programme la direction */
  }
}

void consigneMoteur() {
  if (vitesseCourante > 0) {
    digitalWrite(stepPin, LOW);
    delay(1);
    digitalWrite(stepPin, HIGH);
  }
}

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  /* Met le reset à l'état bas */
  digitalWrite(resetPin, LOW);
  pinMode(resetPin,OUTPUT);
  delay(1);

  /* Met le reste à l'état haut */
  digitalWrite(resetPin, HIGH);
  delay(100);

  digitalWrite(dirPin,HIGH);
  pinMode(13, OUTPUT);

  /* 
   * Configuration des liaisons série
   */
  /* Ligne série 3 reliée à la rpi2 */
  Serial3.begin(115000);
  /* recopie des réceptions/transmissions sur la console */
  Serial.begin(115000);
  /*
   * Configuration du gestionnaire d'évenements
   */
  serial3Mgr.addEvent(autobootEvt);
  serial3Mgr.addEvent(ubootEvt);
  serial3Mgr.addEvent(xvisorEvt);
  serial3Mgr.addEvent(xvisorGuestLaunchedEvt);
  serial3Mgr.addEvent(xvisorVserialEvt);
  serial3Mgr.addEvent(trampolineEvt);
  serial3Mgr.addEvent(trampolineRunEvt);

  Serial.println("Startup");
  
}

void loop() {  
  serial3Mgr.execute();
//  consigneMoteur();
}

/*
Hit any key to stop autoboot:
U-Boot>
XVisor#
guest0: Kicked
[guest0/uart0] arm_init 1
[guest0/uart0] arm_init 2
[guest0/uart0] Virt-v7 Trampoline Firmware from trampoline git
[guest0/uart0] trampoline#
[guest0/uart0] <requete> analogRead A0
[guest0/uart0] <requete> analogRead A1
[guest0/uart0] <requete> digitalWrite 12 HIGH
*/

