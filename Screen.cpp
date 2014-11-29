#include "Screen.h"

Screen::Screen(Adafruit_ST7735* tft) {
	this->tft = tft;
	this->height = 160;
	this->width = 128;
}
