#include "List.h"
#include <assert.h>

List::List()
{
	// Initialize an empty List
	head = 0;
	tail = 0;
	current = 0;
}
void List::insert(const ListElementType& elem)
{
	// precondition: list is in order
	Link addedNode(new Node);
	assert(addedNode);  
	addedNode->elem = elem;
	// Special case: if the existing list is empty, or if the new data
	// is less than the smallest item in the list, the new node is added
	// to the front of the list
	if (head == 0 || elem <= head->elem) {
		addedNode->next = head;
		head = addedNode;
	}
	else {
		// find the pointer to the node that is the predecessor
		// to the new node in the in-order list
		Link pred(head);
		// assertion: pred->elem <= addedNode->elem
		while (pred->next != 0 && pred->next->elem <= addedNode->elem)
			// loop invariant: pred->next != 0 && pred->next->elem <= elem
			pred = pred->next;
		// assertion 7-1: (pred->elem <= addedNode->elem) &&
		//	(addedNode->elem <= pred->next->elem || pred->next == 0) 
		addedNode->next = pred->next;
		pred->next = addedNode;
		// assertion: pred->elem <= pred->next->elem &&
		//	(pred->next->elem <= pred->next->next->elem || pred->next->next == 0)
	}
	// postcondition: list is in order, with elem added in proper position
}

bool List::first(ListElementType& elem)
{
	// After calling first, current points to first item in list
	if (head == 0)
		return false;  
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}
bool List::next(ListElementType& elem)
{
	// with proper use, current should always be nonzero  
	assert(current);

	// After each call, current always points to the item
	// that next has just returned.
	if (current->next == 0) 
		return false;
	else {
		current = current->next;
		elem = current->elem;  
		return true;
	}
}
void List::del()
{
	while (head != 0) {
		Link delNode = head;
		head = head->next;  
		delete delNode;
	}
}