#pragma once
typedef int ListElementType;

class List {
public:
	List();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);  
	bool previous(ListElementType& elem);
private:
	struct Node; // declaration without definition
	typedef Node* Link;  
	struct Node {
		ListElementType elem;
		Link next;
		Link prev;
	};
	Link head;  Link current;
};
