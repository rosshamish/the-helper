/*
Subclass of ZZSprite.cpp

Implementating a box shaped object
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>


class Rectangle {
private:
	int x;
	int y;
	int height;
	int width;
public:
	// Constructor
	Rectangle(int x, int y, int height, int width);

	// Methods
	void drawShape(Adafruit_ST7735 tft);

	void redrawBackground(Adafruit_ST7735 tft);

	void moveX(Adafruit_ST7735 tft);
};

#endif