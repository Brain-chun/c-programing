// project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "List.h"
#include<iostream>
using namespace std;

int main() {
	List l;
	ListElementType i;
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
		cout << elem << endl;
		notEmpty = l.next(elem);
	}
	cout << "*********Inorder 함수와 비교***********" << endl;
	cout << "dummy head nodes는 Inorder와는 다르게 초기 세팅값을 dummy node를 head 값에 할당한다." << endl;
	cout << "또한, head->next 값에 NULL을 할당하게 된다. 때문에 첫 번째 노드인 dummy가 추가되므로, 추가적인 판단 없이 노드를 추가한다." << endl;
	cout << "데이터 추가 작업이 많은 링크드 리스트라면 dummy 노드를 사용하는게 좀 더 효율이 좋아보인다." << endl;
}