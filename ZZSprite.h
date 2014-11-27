
// The sprite class holds instance of a sprite
// It will inherit from a motion class to move

// Goal for tonight: COMPLETED
/*
A Sprite class that can be constructed and have an image added.
And then draw this image on the screen.

Goal for before the weekend:

Store my own test image on the SD card, and read it off
Size parameters
Move the sprite
*/

#ifndef ZZ_SPRITE
#define ZZ_SPRITE

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <lcd_image.h>

class ZZSprite {
private:

public:
	lcd_image_t currentImage;
	int x;
	int y;

	// Methods
	void addImage(lcd_image_t image);

	void drawSprite(Adafruit_ST7735 tft);

};

#endif
