// Double_LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List l;
	ListElementType i; // header file defines this to be int  
	cout << "Hello 20180622 천범수" << endl;
	cout << "Enter items to add to list, add 0 to stop: ";
	cin >> i;
	while (i != 0) {
		l.insert(i);
		cin >> i;
	}
	cout << "Here are the items in the list.\n";
	ListElementType elem;
	bool notEmpty(l.first(elem));
	while (notEmpty) {
		cout << elem << "  ";
		notEmpty = l.next(elem);
	}
	
	return 0;
}