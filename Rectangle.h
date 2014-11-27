/*
Subclass of ZZSprite.cpp

Implementating a box shaped object
*/

#ifndef RECTANGLE
#define RECTANGLE

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

class Rectangle {
private:
	int height;
	int width;
public:
	// Constructor
	Rectangle(int height, int width);

	// Methods
	void drawShape(Adafruit_ST7735 tft);
}

#endif