#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

list* llNew() {
	list* myList = (list*) malloc(sizeof(list));
	myList->length = 0;
	myList->head = NULL;
	myList->tail = NULL;

	return myList;
}

/*
The head node in the list has NULL previous pointer!
*/

void addToEnd(list* myList, Rectangle* shape) {
	// Create a new node
	node* newNode = (node*) malloc(sizeof(node));
	newNode->shape = shape;
	newNode->next = NULL;
	newNode->prev = NULL;

	// Add to list
	// 
	if (myList->length == 0) {
		// List is currently empty
		myList->head = newNode;
	}
	else {
		// Add after tail element
		myList->tail->next = newNode;
		newNode->prev = myList->tail;;
	}

	// Adjust end pointer and length
	myList->tail = newNode;
	myList->length += 1;

}

void printList(list* mylist) {
	Serial.begin(9600);
	// Traverse the entire list, printing each node
	node* currentNode = mylist->head;
	while (currentNode != NULL) {
		// Print the node
		Rectangle* currentShape = currentNode->shape;
		Serial.println(currentShape->getX());

		currentNode = currentNode->next;
	}
	
}

bool checkForCollision_ll(list* myList) {
	// Move accross list and check for overlap
	// every node has to be checked against every other node
	// Compare every node against every other node

	node* referenceNode = myList->head;
	// Every node is the refence node EXCEPT the tail node, because it would be redundant
	while (referenceNode->next != NULL) {
		// Starting from the node immediately after the reference node
		node* currentNode = referenceNode->next;
		// All the way till the last node
		while (currentNode != NULL) {
			// if currentNode and reference node overlab, COLLISION
			Rectangle* referenceRect = referenceNode->shape;
			Rectangle* currentRect = currentNode->shape;
			bool collision = false;
			collision = checkOverlap(referenceRect, currentRect);

			if (collision) {
				// the two shapes collided pass them back through the parameters
				return true;
			}
			currentNode = currentNode->next;
		}
		referenceNode = referenceNode->next;
	}

	// one and two will leave as null if it returns here
	return false;
}

bool checkOverlap(Rectangle* referenceRect, Rectangle* currentRect) {
	// Get image of referenceRect
	int left = referenceRect->getX();
	int right = left + referenceRect->getWidth();
	int top = referenceRect->getY();
	int bottom = top + referenceRect->getHeight();

	// Get image of currentRect
	int left2 = currentRect->getX();
	int right2 = left + currentRect->getWidth();
	int top2 = currentRect->getY();
	int bottom2 = top + currentRect->getHeight();

	// Check for image overlap
	// reference hitting from left
	if (right == left2) {
		return true;
	}
	// hitting from right
	else if (left == right2) {
		return true;
	}
	// hitting from top
	else if (bottom == top2) {
		return true;
	}
	// hitting bottom
	else if (top == bottom2) {
		return true;
	}

	return false;

}