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

// Only check for collisions with the delegate 
Rectangle* checkForCollision_ll(list* myList, Rectangle* delegate) {
	node* delegateNode = findNode(myList, delegate);
	//Serial.begin(9600);
	// Serial.println("found node");
	Rectangle* delegateRect = delegateNode->shape;
	// Check all other nodes for collision against this node
	node* currentNode = myList->head;
	bool collision = false;
	while (currentNode != NULL) {
		// Don't compare with itself
		if (currentNode == delegateNode) {
			currentNode = currentNode->next;
			continue;
		}

		// Check for collision between current and delegate
		Rectangle* currentRect = currentNode->shape;
		collision = checkEachCollisionSide(currentRect, delegateRect);

		if (collision) {
			return currentRect;
		}

		// Go on to next node
		currentNode = currentNode->next;
	}
	return NULL;
}

node* findNode(list* myList, Rectangle* shape) {
	// Start from the head
	node* currentNode = myList->head;
	while (currentNode != NULL) {
		if (currentNode->shape == shape) {
			// Found the node
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}

// Compare each Rectangle with the delegate
bool checkEachCollisionSide(Rectangle* referenceRect, Rectangle* delegateRect) {

	// Get image of referenceRect
	int x = referenceRect->getX();
	int width = referenceRect->getWidth();
	int y = referenceRect->getY();
	int height = referenceRect->getHeight();

	// Get image of delegateRect
	int xDel = delegateRect->getX();
	int widthDel = delegateRect->getWidth();
	int yDel = delegateRect->getY();
	int heightDel = delegateRect->getHeight();

	Serial.begin(9600);
	Serial.println(yDel);
	delay(20);

	// int left = referenceRect->getX();
	// int right = left + referenceRect->getWidth();
	// int top = referenceRect->getY();
	// int bottom = top + referenceRect->getHeight();

	// // Get image of delegateRect
	// int leftDel = delegateRect->getX();
	// int rightDel = leftDel + delegateRect->getWidth();
	// int topDel = delegateRect->getY();
	// int bottomDel = topDel + delegateRect->getHeight();

	// if (x < xDel + widthDel &&
	// 	x + width > xDel    &&
	// 	y < yDel + heightDel &&
	// 	height + y > yDel) {
	// 	// Collision detected
	// 	// Freeze it where it is
	// 	Serial.begin(9600);
	// 	Serial.println("collision");
	// 	delay(20);

	// 	return true;
	// }

	// Collision from the bottom
	if ((yDel + heightDel) == y) {
		Serial.begin(9600);
		Serial.println("bottom");
	}

	return false;

}