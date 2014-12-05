/*
Rectangle class: subclass of screen

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
	int color;

	int originalX;
	int originalY;

public:
	// Constructor
	Rectangle(int x, int y, int height, int width, Adafruit_ST7735* tft, int color);

	// Getters
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getOriginalX();
	int getOriginalY();

	// Setters
	void setX(int newX);
	void setY(int newY);

	// Methods
	void drawShape();
	void redrawBackground();
	void setColor(int color);
	void hideShape();

	// Move
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
};

#endif