
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <SD.h>

// Joystick Pins
const int HORIZ = 0;
const int VERT = 1;
const int SEL = 9;

// upon being setup delegate a shape
// there is an option to switch the shape via a method
// adjust for motion method that handles movement of these shape

#include "Rectangle.h"

class JoyStick {
private:
	uint16_t vertDefault;
	uint16_t horizDefault;

	uint16_t vertDiff;
	uint16_t horizDiff;

	// just changed to a pointer
	Rectangle* delegate; 
public:
	// Constructor
	JoyStick();

	void addDelegate(Rectangle* delegate);

	bool adjustPosition(Adafruit_ST7735 tft);

};

#endif