#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int height, int width, Adafruit_ST7735* tft): Screen(tft) {
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


void Rectangle::drawShape() {
	tft->drawRect(this->x, this->y, this->height, this->width, 0xFFFF);
	tft->fillRect(this->x, this->y, this->height, this->width, 0xFFFF);
}

void Rectangle::redrawBackground() {
	tft->drawRect(this->x, this->y, this->height, this->width, 0x0000);
	tft->fillRect(this->x, this->y, this->height, this->width, 0x0000);
}

void Rectangle::moveRight() {
	// Redraw old position
	redrawBackground();

	// Adjust and draw new
	this->x = x + 1;
	drawShape();
}

void Rectangle::moveLeft() {
	redrawBackground();

	this->x = x - 1;
	drawShape();
}

void Rectangle::moveUp() {
	redrawBackground();

	this->y = y + 1;
	drawShape();
}

void Rectangle::moveDown() {
	redrawBackground();

	this->y = y - 1;
	drawShape();
}






