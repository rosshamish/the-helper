/*
Joystick class : subclass of Screen

Responsible for instigating movement by reading the joystick pins
Controls one delegate and one scene
Calls checkForMotion on the scene it controls

*/

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
#include "Scene.h"

class JoyStick: public Screen {
private:
	uint16_t vertDefault;
	uint16_t horizDefault;
	
	// Only control one scene, one delegate at a time
	Scene* scene;
	Rectangle* delegate;

public:
	// Constructor
	JoyStick(Adafruit_ST7735* tft);

	void addHandle(Scene* scene, Rectangle* delegate);

	// Handle motion of the controlled shape
	Rectangle* adjustPosition();
};

#endif