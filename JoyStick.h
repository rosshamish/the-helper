
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

#include "Rectangle.h"
#include "Screen.h"

class JoyStick: public Screen {
private:
	uint16_t vertDefault;
	uint16_t horizDefault;

	float scrollMultiplier;
	// just changed to a pointer
	Rectangle* delegate; 
	void checkBounds();
public:
	// Constructor
	JoyStick(float mult, Adafruit_ST7735* tft);

	// Add shape to control
	void addDelegate(Rectangle* delegate); 

	// Handle moving of the shape
	bool adjustPosition();

};

#endif