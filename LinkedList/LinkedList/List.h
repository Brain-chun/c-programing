typedef int ListElementType;

class List {
	// Use L to mean "this List"  
	public:
		List();
	// Precondition: None
// Postcondition: L is an empty List
		void insert(const ListElementType& elem);
	// Precondition: None
	// Postcondition: Lpost = Lpre with an instance of elem added to Lpost 
		bool first(ListElementType & elem);
	// Precondition: None
	// Postcondition: If the list is empty, none. Otherwise, the variable
	//	elem contains the first item in L; the "next" item to be returned
	//	is the second in L.
	// Returns: true if and only if there is at least one element in L.
		bool next(ListElementType& elem);
	// Precondition: The "first" operation has been called at least once.
	// Postcondition: Variable elem contains the next item in L, if there is one,
	//	and the next counter advances by one; if there is no next element, none.
	// Returns: true if and only if there was a next item.  
		void del();
	//Precondition: None
	//Postcondition: all nodes will be delete in first to end
	//Returns : None
	private:
		struct Node; // declaration without definition  
		typedef Node *Link; // use declaration of Node  
		struct Node { // now we define Node
		ListElementType elem;  
		Link next;
};
Link head;
Link tail;
Link current;
};
