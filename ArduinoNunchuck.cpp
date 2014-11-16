// Do not remove the include below
#include "ArduinoNunchuck.h"
#include "Arduino.h"
#include <Wire.h>

ArduinoNunchuck::ArduinoNunchuck() {
	cButton = zButton = false;
	joyX = joyY = accelX = accelY = accelZ = 0;

}

void ArduinoNunchuck::init() {
	Wire.begin();
	sendByte(0x55, 0xF0);
	sendByte(0x00, 0xFB);
	delay(100);
	update();
	delay(100);
}

void ArduinoNunchuck::update() {
	int count = 0;
	int values[6];

	Wire.requestFrom(NUNCHUCK_ADDRESS, 6);

	while (Wire.available()) {
		values[count] = decode_byte(Wire.read());
		count++;
	}

	joyX = values[0];
	joyY = values[1];
	accelX = (values[2] << 2) | ((values[5] >> 2) & 3);
	accelY = (values[3] << 2) | ((values[5] >> 4) & 3);
	accelZ = (values[4] << 2) | ((values[5] >> 6) & 3);
	zButton = !((values[5] >> 0) & 1);
	cButton = !((values[5] >> 1) & 1);

	sendByte(0x00, 0x00);
}

void ArduinoNunchuck::sendByte(byte data, byte location) {
	Wire.beginTransmission(NUNCHUCK_ADDRESS);
	Wire.write(location);
	Wire.write(data);
	Wire.endTransmission();
	delay(10);
}

byte ArduinoNunchuck::decode_byte(byte x) {
	x = (x ^ 0x17) + 0x17;
	return x;
}
