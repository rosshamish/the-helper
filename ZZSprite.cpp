#include "ZZSprite.h"
#include <lcd_image.h>

ZZSprite::ZZSprite(int x, int y) {
	this->x = x;
	this->y = y;
}

void ZZSprite::moveX() {
	this->x = this->x + 1;
}