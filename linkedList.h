
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
	Rectangle shape; 
	struct  link * next;
	struct link * prev;
} node;

/*
Entire list
*/
typedef struct {
	int length; 
	link * first;
	link * last;
} list;

/*
Methods
*/

void addToEnd(list* mylist, Rectangle shape);

void printList(list* myList);

#endif