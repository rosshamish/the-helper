/*
Scene Class

Stores a linked list of added shapes
Checks for map boundaries
Checks for collisions between shapes
*/

#ifndef SCENE_H
#define SCENE_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#include "Rectangle.h"
#include "linkedList.h"
#include "Screen.h"

class Scene: public Screen {
private:
	list* llShapes;
public:
	// Constructor
	Scene();

	void addToScene(Rectangle* rect);

	void traverseScene();

	Rectangle* checkForCollision(Rectangle* delegate);

	void checkBounds(Rectangle* delegate);

};

#endif