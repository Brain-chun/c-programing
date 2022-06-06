#pragma once
#include <assert.h>
//
//const int maxQueue = 4;
//
//template < class queueElementType >
//class Queue {
//public: 
//	Queue();
//	~Queue();//destructor
//	void enqueue(queueElementType e); 
//	queueElementType dequeue();  
//	queueElementType front();
//	bool isEmpty(); 
//	bool isFull();
//private:
//	int f; // marks the front of the queue
//	int r; // marks the rear of the queue
//	queueElementType elements[maxQueue];
//	int m_nElement;
//};
//
//int nextPos(int p)
//{
//	if (p == maxQueue - 1) // at end of circle
//		return 0;  else
//		return p + 1;
//}
//
//template < class queueElementType >  Queue < queueElementType >::Queue()
//{
//	// start both front and rear at 0
//	f = 0;
//	r = 0;
//	m_nElement = 0;
//}
//
//template < class queueElementType > 
//Queue < queueElementType >::~Queue()
//{
//	
//}
//
//template < class queueElementType >  void
//Queue < queueElementType >::enqueue(queueElementType e)
//{// add e to the rear of the queue, advancing r to next position
//	//assert(nextPos(r) != f);
//	assert(!isFull());
//	r = nextPos(r); 
//	elements[r] = e;
//	m_nElement++;
//}
//
//
//template < class queueElementType >  queueElementType
//Queue < queueElementType >::dequeue()
//{
//	// advance front of queue, return value of element at the front 
//	//assert(f != r);
//	assert(!isEmpty());
//	f = nextPos(f);  
//	m_nElement--;
//	return elements[f];
//}
//
//template < class queueElementType >  queueElementType
//Queue < queueElementType >::front()
//{
//	// return value of element at the front  
//	//assert(f != r);
//	assert(!isEmpty());
//	return elements[nextPos(f)];
//}
//
//template < class queueElementType >  bool
//Queue < queueElementType >::isEmpty()
//{
//	// return true if the queue is empty, that is,
//	// if front is the same as rear
//	//return bool(f == r);
//	return bool(m_nElement == 0);
//}
//
//template < class queueElementType >  bool
//Queue < queueElementType >::isFull()
//{
//	// return true if the queue is empty, that is,
//	// if front is the same as rear
//	//return bool(nextPos(r) == f);
//	return bool(m_nElement == maxQueue);
//}
template < class queueElementType >  class Queue {
public:
	Queue();
	~Queue();
	void enqueue(queueElementType e);
	queueElementType dequeue();
	queueElementType front();  
	bool isEmpty();
private:
	struct Node;
	typedef Node* nodePtr;  
	struct Node {
		queueElementType data;
		nodePtr next;
	};
	nodePtr f; 
	nodePtr r;
};

template < class queueElementType >  Queue < queueElementType >::Queue()
{
	// set both front and rear to null pointers  
	f = 0;
	r = 0;
}
template < class queueElementType >  Queue < queueElementType >::~Queue()
{
	// set both front and rear to null pointers  
	while (!isEmpty())
	{
		dequeue();
	}
}
template < class queueElementType >  void
Queue < queueElementType >::enqueue(queueElementType e)
{
	// create a new node, insert it at the rear of the queue  
	nodePtr n(new Node);
	assert(n);
	n->next = 0;
	n->data = e;
	if (f != 0) { // existing queue is not empty
		r->next = n; // add new element to end of list 
		r = n;
	}
	else {// adding first item in the queue
		f = n; // so front, rear must be same node  
		r = n;
	}
}

template < class queueElementType >  queueElementType
Queue < queueElementType >::dequeue()
{
	assert(f); // make sure queue is not empty 
	nodePtr n(f);
	queueElementType frontElement(f->data);
	f = f->next;
	delete n;
	if (f == 0) // we're deleting last node  
		r = 0;
		return frontElement;
}

template < class queueElementType >
queueElementType
Queue < queueElementType >::front()
{
	assert(f);  
	return f->data;
}

template < class queueElementType >
bool
Queue < queueElementType >::isEmpty()
{
	// true if the queue is empty -- when f is a null pointer
	return bool(f == 0);
}
