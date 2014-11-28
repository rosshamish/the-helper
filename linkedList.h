
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
Single node
*/
typedef struct link{
	int data; 
	struct  link * next;
	struct link * previous;
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

void addToEnd(list* mylist, int data);

void printList(list* myList);

#endif
