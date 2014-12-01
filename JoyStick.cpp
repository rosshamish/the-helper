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

void JoyStick::addScene(Scene* scene) {
	this->scene = scene;
}

Rectangle* JoyStick::adjustPosition() {
	/*
	If movement is necessary, then move
	*/

	int16_t vertDiff = analogRead(VERT) - this->vertDefault;
	int16_t horizDiff = analogRead(HORIZ) - this->horizDefault;

	bool motionHappened = false;
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
	Things to do if there is movement
	*/

	Rectangle* collidedShape = NULL;

	if (motionHappened) {
		// Ensure still on screen
		this->scene->checkBounds(this->delegate);

		// Check the scene for collision
		collidedShape = this->scene->checkForCollision(this->delegate);

	}

	// Chill out and go slow
	delay(20);

	// Alert if collision happened
	return collidedShape;
}



