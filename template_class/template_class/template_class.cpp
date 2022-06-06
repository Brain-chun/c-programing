// template_class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include"Pair.h"
using namespace std;

int main()
{
	cout << "hello 20180622 천범수" << endl;

	Pair<int> p(2, 3);
	cout << "First is " << p.GetFirst() <<" second is "<<p.GetSecond() << endl;
	p.SetFirst(10);
	p.SetSecond(20);
	cout << "First is " << p.GetFirst() << " second is " << p.GetSecond() << endl;

	Pair<char> p2('a', 'b');
	cout << "First is " << p2.GetFirst() << " second is " << p2.GetSecond() << endl;
	p2.SetFirst('c');
	p2.SetSecond('d');
	cout << "First is " << p2.GetFirst() << " second is " << p2.GetSecond() << endl;
}

