#ifndef __MCP23S17_H__
#define __MCP23S17_H__
#include <stdint.h>

typedef void (*mcpCallBack)();

class mcp23s17 {

	public:
	typedef enum {PORTA=0, PORTB=1} port;
	typedef enum {OUTPUT=0,INPUT=1,INPUT_PULLUP=2} mode;
	typedef enum {RISING, FALLING, BOTH} itType;

	private:
	enum reg {	//use mode 0 (default)
			IODIRA   = 0x0,	//direction input(1), output(0)
			IODIRB   = 0x1,
			IOPOLA   = 0x2,	//polarity (toggle) -> not used
			IOPOLB   = 0x3,
			GPINTENA = 0x4,	//interrupt on change
			GPINTENB = 0x5,
			DEFVALA  = 0x6,	//default value (pin differs => it)
			DEFVALB  = 0x7,
			INTCONA  = 0x8,	// if if pin!=defval(1) or
			INTCONB  = 0x9,	// pin!=previous => edge detection(0)
			IOCON    = 0xA,	// or 0xB. Config. default Ok => not used
			GPPUA    = 0xC,	//pullup
			GPPUB    = 0xD,
			INTFA    = 0xE,	//interrupt flag
			INTFB    = 0xF,
			INTCAPA  = 0x10, //gpio capture
			INTCAPB  = 0x11,
			GPIO_A   = 0x12, /* GPIOA reserved for STM32 */
			GPIO_B   = 0x13,
			OLATA	 = 0x14, //output latch
			OLATB	 = 0x15,
		};
	//store latch config, to remove read operation during ouput access.
	uint8_t mOLAT[2];
	//interrupt edge type.
	itType mItTypeTab[16];
	//callback associated to the interrupt
	mcpCallBack mCallbacks[16];


	//write to a MCP register, using spi.
	void writeReg(uint8_t reg, uint8_t val);
	//read a mcp register.
	uint8_t readReg(uint8_t reg);
	//just update one bit.
	void setBitInReg(uint8_t reg, uint8_t bitNum);
	void clearBitInReg(uint8_t reg, uint8_t bitNum);

	public:
		mcp23s17();
		void begin();
		//configure a pin
		// - port is PORTA or PORTB
		// - numBit is the pin number (0 to 7)
		// - mode is in DISABLE, OUTPUT, INPUT, ...)
		int pinMode(	port p,
				uint8_t bitNum,
				mode m);
		//set a pin, previously configured as OUTPUT
		// high state if 'value' is different from 0
		// low state if 'value' is 0.
		void digitalWrite(  port p,
				    uint8_t bitNum,
				    bool value);
                // read a pin, previously configured as OUTPUT
                // high state if 'value' is different from 0
                // low state if 'value' is 0.
                // -1 is bitNum is above 7.
                int8_t digitalRead(    port p,
                                        uint8_t bitNum);
                // toggle a pin, previously configured as OUTPUT
                void digitalToggle( port p,
                                    uint8_t bitNum);
		//set several bits of the same port in the same time.
		//for each bit of the bitfield:
		// 1 - set the bit
		// 0 - no effect
		void setBits(port p,uint8_t bitField);
		//clear several bits of the same port in the same time.
		//for each bit of the bitfield:
		// 1 - clear the bit
		// 0 - no effect
		void clearBits(port p,uint8_t bitField);
		//update the whole port (output pins)
		//for each bit of the bitfield:
		// 1 - set the bit
		// 0 - clear the bit
		void writeBits(port p,uint8_t val);
		//read the whole port.
		uint8_t readBits(port p);

		//attach an interrupt to an input pin (port/bitNum)
		//void attachInterrupt(port p, uint8_t bitNum, itType type,mcpCallBack callback);
		void attachInterrupt(port p, uint8_t bitNum);
		//remove the interrupt associated to a pin.
		void detachInterrupt(port p, uint8_t bitNum);

		//function that SHOULD be called in the interrupt Handler (EXTI..).
		// interrupt on PORT B only. result is a mask
		// detect FALLING edge only!!
		char getInterrupt();
};

extern mcp23s17 ioExt;

#endif
