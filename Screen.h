
#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <SD.h>

class Screen {
private:
public:
	Adafruit_ST7735* tft;
	int width;
	int height;

	Screen(Adafruit_ST7735* tft);
};

#endif

