#include "JoyStick.h"

// Constructor
JoyStick::JoyStick(Adafruit_ST7735* tft): Screen(tft) {
	// Grab default readings and store in some private variables
	this->vertDefault = analogRead(VERT);
	this->horizDefault = analogRead(HORIZ);
}

// Add a Rectangle and scene to be checked for motion
void JoyStick::addHandle(Scene* scene, Rectangle* delegate) {
	this->scene = scene;
	this->delegate = delegate;
}

// Check for motion
// If there was motion, call appropriate functions to check for collisions
Rectangle* JoyStick::adjustPosition() {
	bool motionHappened = false;
	/*
	If movement is necessary, then move
	*/
	int16_t vertDiff = analogRead(VERT) - this->vertDefault;
	int16_t horizDiff = analogRead(HORIZ) - this->horizDefault;

	// Go down
	if (vertDiff < -10) {
		this->delegate->moveUp();
		// Check to make sure in bounds
		motionHappened = true;
	}
	// Go up
	if (vertDiff > 10) {
		this->delegate->moveDown();
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

	/*
	If there was motion, ensure still on screen and also check for collisions
	*/
	Rectangle* collidedShape = NULL;

	if (motionHappened) {
		// Ensure still on screen
		this->scene->checkBounds(this->delegate);

		// Check the scene for collision
		collidedShape = this->scene->checkForCollision(this->delegate);

	}

	// Chill out and go slow, we want the joystick to be a reasonable speed
	delay(20);

	// Alert if collision happened
	return collidedShape;
}



