#include "Scene.h"

// Constructor
Scene::Scene(): Screen(tft) {
	this->llShapes = llNew();
}

// Add Rectangle to scene
void Scene::addToScene(Rectangle* rect) {
	addToEnd(llShapes, rect);
}

// Remove Rectangle from scene
void Scene::removeFromScene(Rectangle* target) {
	removeFromList(llShapes, target);
}

// Mainly for debugging, traverse and print all shapes in scene
void Scene::traverseScene() {
	printList(llShapes);
}

// Make sure the shape that moved is still on the screen
void Scene::checkBounds(Rectangle* delegate) {
	// Cross reference vs the Screen's size

	// X
	if (delegate->getX() <= 0) {
		delegate->moveRight();
	}
	else if ((delegate->getX() + delegate->getWidth()) > this->width) {
		delegate->moveLeft();
	}

	// Y
	if (delegate->getY() <= 0) {
		delegate->moveDown();
	}
	else if ((delegate->getY() + delegate->getHeight()) > this->height) {
		delegate->moveUp();
	}
}

// Draw entire scene either in original state or current state depending on arguement
void Scene::drawScene(bool original) {
	// Function from linked list
	drawEachElement(llShapes, original);
}

// Hide entire scene in orginal state or in current state depending on arguement
void Scene::hideScene(bool original) {
	// Function from linked list
	hideEachElement(llShapes, original);
}

// Ask the linked list member data if there was a collision
//
//@Callee: Joystick.cpp (on every movement of delegate)
//@Returns: Rectangle* of collided shape (or null)
Rectangle* Scene::checkForCollision(Rectangle* delegate) {
	// The linked list will check if there are any collisions
	Rectangle* collidedShape = NULL;
	collidedShape = checkForCollision_ll(llShapes, delegate);

	// Return this collided shape if it there was in fact a collision
	if (collidedShape != NULL) {
		return collidedShape;
	}

	return NULL;
}


