#include "Scene.h"

Scene::Scene() {
	this->llShapes = llNew();
}

void Scene::addToScene(Rectangle* rect) {
	addToEnd(llShapes, rect);
}

void Scene::traverseScene() {
	printList(llShapes);
}

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