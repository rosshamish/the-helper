/*
Scene Class

A grouping shapes will be checked for collisons by this class

1. Shapes are added to this class and stored as a linked list
2. Everytime the delegate moves in the scene moves, check for conflicts
3. A conflict is when there is intersection of shapes (box-based)
4. Alert the colliding objects of their collison

*/

#ifndef SCENE_H
#define SCENE_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#include "Rectangle.h"
#include "linkedList.h"

class Scene {
private:
	list* llShapes;
public:
	// Constructor
	Scene();

	// Add to scene
	void addToScene(Rectangle* rect);

	void traverseScene();

	void checkForCollision();

};

#endif