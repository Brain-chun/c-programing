#pragma once
// Code Example 7-1: List ADT header file
//#include ".h"
// the type of the individual elements in the list is defined here  
typedef int ListElementType;
// implementation specific stuff here  
const int maxListSize = 1000;

class List {
public:
	List();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);  bool next(ListElementType& elem);
private:
	ListElementType listArray[maxListSize];
	int numberOfElements;  int currentPosition;
};
