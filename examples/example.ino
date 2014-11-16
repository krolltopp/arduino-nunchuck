#include <ArduinoNunchuck.h>
#include "Arduino.h"

#define BAUDRATE 9600

ArduinoNunchuck arduinoNunchuck;

void setup() {
	Serial.begin(BAUDRATE);
	arduinoNunchuck.init();
}

void loop() {
	arduinoNunchuck.update();
	printData();
	delay(500);
}

void printData() {
	Serial.print("accelX = ");
	Serial.print(arduinoNunchuck.getAccelX(), DEC);
	Serial.print(", accelY = ");
	Serial.print(arduinoNunchuck.getAccelY(), DEC);
	Serial.print(", accelZ = ");
	Serial.println(arduinoNunchuck.getAccelZ(), DEC);
}
