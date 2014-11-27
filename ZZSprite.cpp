#include "ZZSprite.h"
#include <lcd_image.h>

void ZZSprite::addImage(lcd_image_t image) {
	currentImage = image;
}

void ZZSprite::drawSprite(Adafruit_ST7735 tft) {
	// Draw the image on the screen
	// use lcd image draw
	lcd_image_draw(&currentImage, &tft, 0, 0, 0, 0, 128, 128);
}