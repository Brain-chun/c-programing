#include "List.h";
#include<assert.h>
List::List()
{
	// Initialize an empty list
	head = new Node;
	assert(head);
	head->next = 0;
	current = 0;
}
void List::insert(const ListElementType& elem)
{
	// precondition: list is in order
	Link addedNode(new Node);
	assert(addedNode);
	addedNode->elem = elem;
	// find the pointer to the node that is the predecessor
	// to the new node in the in-order list
	Link pred(head);
	// loop invariant: pred>elem <= elem
	while (pred->next != 0 && (pred->next->elem <= addedNode->elem))
		pred = pred->next;
	// assertion 7-1: (pred>elem <= addedNode>elem) &&
	   //      (addedNode->elem <= pred->next->elem || pred->next == 0)
	addedNode->next = pred->next;
	pred->next = addedNode;
	// postcondition: list is in order
}
bool List::first(ListElementType& elem)
{
	// After calling first, current points to first item in list
	assert(head); // if no head, something is very wrong!
	if (head->next == 0)
		return false;
	else {
		current = head->next;
		elem = current->elem;
		return true;
	}
}
bool List::next(ListElementType& elem)
{
	// With proper use, current should always be nonzero
	assert(current);
	// After each call, current always points to the item
	  // that next has just returned.
	if (current->next == 0)
		return false; // no next element available
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}
void List::remove(const ListElementType& target)
{
	assert(head);
	Link pred, delNode;
	// pred starts out pointing at the dummy head
	for (pred = head; pred->next != 0 && pred->next->elem < target; pred = pred->next);
	// at this point, check to see if we've found target --
	// if so, remove it
	// Have to check carefully to make sure we don't
	// dereference a null pointer!
	if (pred && (pred->next) && (pred->next->elem == target)) {
		// remove the next node in the list
		delNode = pred->next;
		pred->next = delNode->next;
		delete delNode; // return node to memory
	}
}