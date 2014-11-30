#include "JoyStick.h"

// The scene handles the collisons..this makes sense and should be this way
// For now, make the joystick call the scene checkForCollisions method
// So the joystick will have to inherit from the scene

JoyStick::JoyStick(Adafruit_ST7735* tft): Screen(tft) {
	// Grab default readings and store in some private variables
	this->vertDefault = analogRead(VERT);
	this->horizDefault = analogRead(HORIZ);
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
		// Check to make sure in bounds
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
	checkBounds();

	// Check the scene for collision
	this->scene->checkForCollision(this->delegate);

	// Chill out and go slow
	delay(10);

	// Alert if motion happened
	return motionHappened;
}

void JoyStick::checkBounds() {
	// Cross reference vs the Screen's size

	// X
	if (this->delegate->getX() <= 0) {
		// bound
		this->delegate->moveRight();
	}
	else if (this->delegate->getX() > (this->width - this->delegate->getWidth())) {
		this->delegate->moveLeft();
	}

	// Y
	if (this->delegate->getY() <= 0) {
		this->delegate->moveUp();
	}
	else if (this->delegate->getY() > (this->height - this->delegate->getHeight())) {
		this->delegate->moveDown();
	}
}

void JoyStick::addScene(Scene* scene) {
	this->scene = scene;
}


