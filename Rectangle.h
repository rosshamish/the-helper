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

#include "Screen.h"

class Rectangle: public Screen {
private:
	int x;
	int y;
	int height;
	int width;

	// Shouldn't every need to be called from outside the class
	void redrawBackground();
public:
	// Constructor
	Rectangle(int x, int y, int height, int width, Adafruit_ST7735* tft);

	// Getters
	int getX();
	int getY();
	int getWidth();
	int getHeight();

	// Setters
	void setX(int newX);
	void setY(int newY);

	// Methods
	void drawShape();

	// Move
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
};

#endif