#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/*
The first node in the list has NULL previous pointer!
*/

void addToEnd(list* myList, Rectangle shape) {
	// Create a new node
	node* newNode = (node*) malloc(sizeof(node));
	newNode->shape = shape;
	newNode->next = NULL;
	newNode->prev = NULL;

	// Add to list
	// 
	if (myList->length == 0) {
		// List is currently empty
		myList->first = newNode;
	}
	else {
		// Add after last element
		myList->last->next = newNode;
		newNode->prev = myList->last;;
	}

	// Adjust end pointer and length
	myList->last = newNode;
	myList->length += 1;

}

void printList(list* mylist) {
	Serial.begin(9600);
	// Traverse the entire list, printing each node
	node* currentNode = mylist->first;
	while (currentNode != NULL) {
		// Print the node
		Rectangle currentShape = currentNode->shape;
		Serial.println(currentShape.getX());

		currentNode = currentNode->next;
	}
	
}