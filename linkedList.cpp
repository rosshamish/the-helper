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

// Draw all the elements
void drawEachElement(list* myList, bool original) {
	// start at the head
	node* currentNode = myList->head;
	while (currentNode != NULL) {
		// draw this node
		Rectangle* currentRect = currentNode->shape;

		// revert back to old state
		if (original) {
			currentRect->setX(currentRect->getOriginalX());
			currentRect->setY(currentRect->getOriginalY());
		}

		currentRect->drawShape();

		// increment
		currentNode = currentNode->next;
	}
}

void hideEachElement(list* myList) {
	// start at the head
	node* currentNode = myList->head;
	while (currentNode != NULL) {
		// hide this node
		Rectangle* currentRect = currentNode->shape;
		currentRect->redrawBackground();

		// increment
		currentNode = currentNode->next;
	}
}

// Only check for collisions with the DELEGATE! 
Rectangle* checkForCollision_ll(list* myList, Rectangle* delegate) {
	node* delegateNode = findNode(myList, delegate);
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

// Used in checkForCollison_ll to locate the delegate
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

void removeFromList(list* myList, Rectangle* target) {
	// find the target
	node* found = findNode(myList, target);

	// Adjust the pointers
	node* previous = found->prev;
	previous->next = found->next;

	if (found->next != NULL) {
		node* next = found->next;
		next->prev = previous;
	}
}

// Do the hard work to find collision and know which side collision is on
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

	// Is there a collision?
	if (x < xDel + widthDel &&
		x + width > xDel    &&
		y < yDel + heightDel &&
		height + y > yDel) {

		Serial.begin(9600);
		Serial.println("collision");
		delay(20);

		/*
		Find which side the collision occured on
		Freeze the delegate there (can't go through collided object)
		*/

		// Bottom
		if (yDel >= (y + height - 1)) {
			delegateRect->redrawBackground();
			referenceRect->drawShape();
			delegateRect->setY(y + height + 1);
			delegateRect->drawShape();
			return true;
		}

		// Top
		if ((yDel + heightDel) <= (y + 1)) {
			delegateRect->redrawBackground();
			referenceRect->drawShape();
			delegateRect->setY(y - heightDel - 1);
			delegateRect->drawShape();
			return true;
		}

		// Left
		if ((xDel + widthDel) <= (x + 1)) {
			delegateRect->redrawBackground();
			referenceRect->drawShape();
			delegateRect->setX(x - widthDel - 1);
			delegateRect->drawShape();
			return true;
		}

		// Right
		if (xDel >= (x + width - 1)) {
			delegateRect->redrawBackground();
			referenceRect->drawShape();
			delegateRect->setX(x + width + 1);
			delegateRect->drawShape();
			return true;
		}

	}
	// No collision
	else {
		return false;
	}
}