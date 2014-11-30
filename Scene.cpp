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

void Scene::checkForCollision() {
	// traverse through scene, checking objects for overlap

	// the scene is lazy and doesn't like to do shit
	// get the linked list to check for collisions
	bool col = false;
	col = checkForCollision_ll(llShapes);

	if (col) {
		Serial.begin(9600);
		Serial.println("there was collision.");
	}
	// collided and collided2 will be non-null if there was a collision
	// if (collided != NULL && collided2 != NULL) {
	// 	Serial.begin(9600);
	// 	Serial.println("There was a collision");
	// }
}