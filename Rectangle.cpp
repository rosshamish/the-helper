#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int height, int width) {
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
}

/*
Getters
*/

int Rectangle::getX() {
	return this->x;
}

int Rectangle::getY() {
	return this->y;
}

/*
Setters 
*/

void Rectangle::setY(int newY) {
	this->y = newY;
}

void Rectangle::setX(int newX) {
	this->x = newX;
}


void Rectangle::drawShape(Adafruit_ST7735 tft) {
	tft.drawRect(this->x, this->y, this->height, this->width, 0xFFFF);
	tft.fillRect(this->x, this->y, this->height, this->width, 0xFFFF);
}

void Rectangle::redrawBackground(Adafruit_ST7735 tft) {
	tft.drawRect(this->x, this->y, this->height, this->width, 0x0000);
	tft.fillRect(this->x, this->y, this->height, this->width, 0x0000);
}

void Rectangle::moveRight(Adafruit_ST7735 tft) {
	// Redraw old position
	redrawBackground(tft);

	// Adjust and draw new
	this->x = x + 1;
	drawShape(tft);
}

void Rectangle::moveLeft(Adafruit_ST7735 tft) {
	redrawBackground(tft);

	this->x = x - 1;
	drawShape(tft);
}

void Rectangle::moveUp(Adafruit_ST7735 tft) {
	redrawBackground(tft);

	this->y = y + 1;
	drawShape(tft);
}

void Rectangle::moveDown(Adafruit_ST7735 tft) {
	redrawBackground(tft);

	this->y = y - 1;
	drawShape(tft);
}






