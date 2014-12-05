/*
Linked List used by Scene to store shapes
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <SD.h>

#include "Rectangle.h"

/*
Single node
*/
typedef struct link{
	Rectangle* shape; 
	struct  link* next;
	struct link* prev;
} node;

/*
Entire list
*/
typedef struct {
	int length; 
	link* head;
	link* tail;
} list;

/*
Methods
*/
list* llNew();

void addToEnd(list* mylist, Rectangle* shape);

void removeFromList(list* myList, Rectangle* target);

void printList(list* myList);

node* findNode(list* myList, Rectangle* shape);

Rectangle* checkForCollision_ll(list* myList, Rectangle* delegate);

bool checkEachCollisionSide(Rectangle* referenceRect, Rectangle* currentRect);

void drawEachElement(list* myList, bool original);

void hideEachElement(list* myList, bool original);

#endif
