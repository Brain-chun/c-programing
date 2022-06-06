// displat15_5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "discountsale.h"
#include "sale.h"
using namespace std;
using namespace SavitchSale;

int main()
{
	cout << "hello 20180622 천범수" << endl;
	Sale simple(10.00);
	DiscountSale discount(11.00, 10);

	cout.setf(ios::fixed || ios::showpoint);
	cout.precision(2);

	if (discount < simple) {
		cout << "discount is a cheeper" << endl;
		cout << "saving is $" << simple.savings(discount) << endl;
	}
	else
		cout << "discount is not cheeper" << endl;
}

