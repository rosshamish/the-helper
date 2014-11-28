#include "Scene.h"

Scene::Scene() {
	this->llShapes = llNew();
}

void Scene::addToScene(Rectangle rect) {
	addToEnd(llShapes, rect);
}

void Scene::traverseScene() {
	printList(llShapes);
}