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

	// Shouldn't every need to be called from outside the class
	void redrawBackground(Adafruit_ST7735 tft);
public:
	// Constructor
	Rectangle(int x, int y, int height, int width);

	// Getters
	int getX();
	int getY();

	// Setters
	void setX(int newX);
	void setY(int newY);

	// Methods
	void drawShape(Adafruit_ST7735 tft);

	// Move
	void moveRight(Adafruit_ST7735 tft);
	void moveLeft(Adafruit_ST7735 tft);
	void moveUp(Adafruit_ST7735 tft);
	void moveDown(Adafruit_ST7735 tft);
};

#endif