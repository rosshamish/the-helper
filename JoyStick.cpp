#include "JoyStick.h"


JoyStick::JoyStick() {
	// Grab default readings and store in some private variables
	this->vertDefault = analogRead(VERT);
	this->horizDefault = analogRead(HORIZ);
}

void JoyStick::addDelegate(Rectangle* delegate) {
	// Assign delegate
	this->delegate = delegate;
}

bool JoyStick::adjustPosition(Adafruit_ST7735 tft) {
	// Store the horiz and very movement in two more private variables
	uint16_t vertCurrent = analogRead(VERT);
	uint16_t horizCurrent = analogRead(HORIZ);

	this->vertDiff = vertCurrent - this->vertDefault;
	this->horizDiff = horizCurrent - this->horizDefault;

	if (this->vertDiff > 10) {
		Rectangle* delegate = this->delegate;
		// Adjust the y position
		int newY = delegate->getY() + 3;
		delegate->setY(newY);
		delegate->drawShape(tft);
		return 1;
	}

	return 0;

}

