#include "Scene.h"

Scene::Scene(): Screen(tft) {
	this->llShapes = llNew();
}

void Scene::addToScene(Rectangle* rect) {
	addToEnd(llShapes, rect);
}

void Scene::traverseScene() {
	printList(llShapes);
}

void Scene::checkBounds(Rectangle* delegate) {
	// Cross reference vs the Screen's size

	// X
	if (delegate->getX() <= 0) {
		// bound
		delegate->moveRight();
	}
	else if (delegate->getX() > (this->width - delegate->getWidth())) {
		delegate->moveLeft();
	}

	// Y
	if (delegate->getY() <= 0) {
		delegate->moveUp();
	}
	else if (delegate->getY() > (this->height - delegate->getHeight())) {
		delegate->moveDown();
	}
}

/*
This will be constantly called when looking for its positionn
*/
Rectangle* Scene::checkForCollision(Rectangle* delegate) {
	// traverse through scene, checking objects for overlap

	// the scene is lazy and doesn't like to do shit
	// get the linked list to check for collisions
	Rectangle* collidedShape = NULL;
	collidedShape = checkForCollision_ll(llShapes, delegate);

	if (collidedShape != NULL) {
		Serial.begin(9600);
		Serial.println("there was collision.");
		return collidedShape;
	}

	return NULL;

	//collidedShape = NULL;

}
