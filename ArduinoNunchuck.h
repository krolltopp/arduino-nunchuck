// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef ArduinoNunchuck_H_
#define ArduinoNunchuck_H
#include "Arduino.h"

class ArduinoNunchuck {
public:
	ArduinoNunchuck();
	void init();
	void update();
private:
	int analogX;
	int analogY;
	int accelX;
	int accelY;
	int accelZ;
	int zButton;
	int cButton;
};

#endif
