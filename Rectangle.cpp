#include "Rectangle.h"

// Constructor
Rectangle::Rectangle(int x, int y, int width, int height, Adafruit_ST7735* tft, int color): Screen(tft) {
	this->x = x;
	this->y = y;
	this->originalX = x;
	this->originalY = y;

	this->width = width;
	this->height = height;
	this->color = color;
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

int Rectangle::getWidth() {
	return this->width;
}

int Rectangle::getHeight() {
	return this->height;
}

int Rectangle::getOriginalX() {
	return this->originalX;
}

int Rectangle::getOriginalY() {
	return this->originalY;
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

void Rectangle::setColor(int color) {
	this->color = color;
}

/*
Movement and Drawing
*/

// Hide shape by drawing background on its coordinates
void Rectangle::hideShape() {
	redrawBackground();
}

// use GFX library functions to draw
void Rectangle::drawShape() {
	tft->drawRect(this->x, this->y, this->width, this->height, this->color);
	tft->fillRect(this->x, this->y, this->width, this->height, this->color);
}

// Draw the image of shape with black (assuming black background)
void Rectangle::redrawBackground() {
	tft->drawRect(this->x, this->y, this->width, this->height, 0x0000);
	tft->fillRect(this->x, this->y, this->width, this->height, 0x0000);
}

// Draw background on old position, move, and redraw
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

	this->y = y - 1;
	drawShape();
}

void Rectangle::moveDown() {
	redrawBackground();

	this->y = y + 1;
	drawShape();
}






