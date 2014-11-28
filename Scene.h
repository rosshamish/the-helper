/*
Scene Class

A grouping shapes will be checked for collisons by this class

1. Shapes are added to this class and stored as a linked list
2. Everytime something in the scene moves, check for conflict
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

class Scene {
private:
	
public:
	// Constructor
	// Use default

	// Add to scene
	void addToScene(Rectangle rect);





};

#endif