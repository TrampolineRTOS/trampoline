#define ON 1
#define OFF 0
#define MAXPWM 40000


sbit SW1 = P2^0;
sbit SW2 = P2^1;
sbit SW3 = P2^2;
sbit SW4 = P2^3;
sbit SW5 = P2^4;
sbit SW6 = P2^5;
sbit SW7 = P2^6;
sbit SW8 = P2^7;

sbit LED1 = P8^0;
sbit LED2 = P8^1;
sbit LED3 = P8^2;
sbit LED4 = P8^3;
sbit LED5 = P8^4;
sbit LED6 = P8^5;
sbit LED7 = P8^6;
sbit LED8 = P8^7;


extern void InitGPIO();
extern void BarGraphLED(unsigned int val, unsigned int valmax);
extern void SetLED(unsigned char no, char etat);
extern void CMDMoteur(int onoff, int sens, unsigned int val);
extern unsigned char GetVPot(unsigned char PotNR);

