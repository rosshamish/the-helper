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
		collision = checkOverlap(currentRect, delegateRect);

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


bool checkOverlap(Rectangle* referenceRect, Rectangle* delegateRect) {
	// Get image of referenceRect
	int left = referenceRect->getX();
	int right = left + referenceRect->getWidth();
	int top = referenceRect->getY();
	int bottom = top + referenceRect->getHeight();

	// Get image of delegateRect
	int leftDel = delegateRect->getX();
	int rightDel = leftDel + delegateRect->getWidth();
	int topDel = delegateRect->getY();
	int bottomDel = topDel + delegateRect->getHeight();

	/*
	There are four sides the collision could come from
	
	The first two cases are from the SIDE
	The last two cases are from the TOP/BOTTOM 
	*/

	if ((rightDel == left) && (topDel <= bottom) && (topDel >= top)) {
		return true;
	}
	if ((leftDel == right) && (topDel <= bottom) && (topDel >= top)) {
		return true;
	}

	// From above/below
	if (bottomDel == top && rightDel >= left && rightDel <= right) {
		return true;
	}
	if (topDel == bottom && rightDel >= left && rightDel <= right) {
		return true;
	}

	return false;

}