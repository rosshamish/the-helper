#include "Rectangle.h"

Rectangle::Rectangle(int height, int width) {
	this->height = height;
	this->width = width;
}

void Rectangle::drawShape(Adafruit_ST7735 tft) {
	tft.drawRect(10, 10, this->height, this->width, 0x0000);
}