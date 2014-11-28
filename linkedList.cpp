#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/*
The first node in the list has NULL previous pointer!
*/

void addToEnd(list* mylist, int data) {
	// Create a new node
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	// Add to list
	// 
	if (mylist->length == 0) {
		// List is currently empty
		myList->first = newNode;
	}
	else {
		// Add after last element
		myList->last->next = newNode;
		newNode->prev = mylist;
	}

	// Adjust end pointer and length
	myList->last = newNode;
	myList->length += 1;

}

void printList(list* mylist) {
	// Traverse the entire list, printing each node
	node* currentNode = mylist->first;
	while (currentNode != NULL) {
		// Print the node
		Serial.println(currentNode->data);

		currentNode = currentNode->next;
	}
	
}