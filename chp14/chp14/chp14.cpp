// chp14.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "hourlyemployee.h"
#include "salariedemployee.h"

using namespace std;
using namespace SavitchEmployees;

int main()
{
    cout << "hello 20180622 천범수" << endl;

    HourlyEmployee aHEmp("john", "323-25-3339", 1.00, 30);
    aHEmp.printCheck();

    SalariedEmployee aSEmp("Jane", "273-38-1234", 3000);
    aSEmp.printCheck();
}
