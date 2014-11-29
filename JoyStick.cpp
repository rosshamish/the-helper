#include "JoyStick.h"


JoyStick::JoyStick(float mult, Adafruit_ST7735* tft): Screen(tft) {
	// Grab default readings and store in some private variables
	this->vertDefault = analogRead(VERT);
	this->horizDefault = analogRead(HORIZ);
	this->scrollMultiplier = mult;
}

void JoyStick::addDelegate(Rectangle* delegate) {
	// Assign delegate
	this->delegate = delegate;
}

bool JoyStick::adjustPosition() {

	int16_t vertDiff = analogRead(VERT) - this->vertDefault;
	int16_t horizDiff = analogRead(HORIZ) - this->horizDefault;

	bool motionHappened = false;
	// Go down
	if (vertDiff < -10) {
		this->delegate->moveDown();
		motionHappened = true;
	}
	// Go up
	if (vertDiff > 10) {
		this->delegate->moveUp();
		motionHappened = true;
	}
	// Go left
	if (horizDiff < -10) {
		this->delegate->moveLeft();
		motionHappened = true;
	}
	// Go right
	if (horizDiff > 10) {
		this->delegate->moveRight();
		motionHappened = true;
	}

	// Chill out and go slow
	delay(10);

	// Alert if motion happened
	return motionHappened;
}

