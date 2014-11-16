// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef ArduinoNunchuck_H_
#define ArduinoNunchuck_H

#define NUNCHUCK_ADDRESS 0x52

class ArduinoNunchuck {
public:
	ArduinoNunchuck();
	void init();
	void update();
	bool isCButton(), isZButton();
	int getJoyX(), getJoyY(), getAccelX(), getAccelY(), getAccelZ();
private:
	void sendByte(byte data, byte location);
	byte nunchuk_decode_byte (byte x);
	int joyX, joyY, accelX, accelY, accelZ;
	bool zButton, cButton;
};

#endif
