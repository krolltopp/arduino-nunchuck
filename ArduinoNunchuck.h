// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef ArduinoNunchuck_H
#define ArduinoNunchuck_H

#include "Arduino.h"
#include <Wire.h>

#define NUNCHUCK_ADDRESS 0x52

class ArduinoNunchuck {
public:
	ArduinoNunchuck();
	void init();
	void update();
	bool isCButtonPressed(), isZButtonPressed();
	void resetButtons();	
	int getJoyX(), getJoyY(), getAccelX(), getAccelY(), getAccelZ();
private:
	void sendByte(byte data, byte location);
	uint8_t decode_byte (byte x);
	int joyX, joyY, accelX, accelY, accelZ;
	bool zButton, cButton;
};

#endif
