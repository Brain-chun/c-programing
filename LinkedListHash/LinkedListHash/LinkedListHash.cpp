// ArrayHash.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Table.h"
#include "CPhone.h"
using namespace std;

int StringToInt(string strName);

ostream& operator <<(ostream& outstream, const CPhone& aPhone)
{
    outstream << "Name: " << aPhone.m_strName << "  Birth: " << aPhone.m_nBirth << endl;
    return outstream;
}


int main()
{
    cout << "Hello 20180622 천범수" << endl;
    Table <int, int> myTable;
    myTable.insert(20200421, 20200421);
    myTable.insert(20200422, 20200422);
    myTable.insert(20200423, 20200423);
    myTable.insert(20200424, 20200424);
    myTable.insert(20200425, 20200425);
    myTable.insert(20200426, 20200426);
    myTable.insert(20200427, 20200427);
    myTable.insert(20200416, 20200416);

    myTable.dump();
    myTable.deleteKey(20200423);
    myTable.deleteKey(20200424);
    myTable.insert(20200412, 20200412);
    myTable.dump();

    Table <int, CPhone> myTable2;

    myTable2.insert(20200421, CPhone("John", 20200421));
    myTable2.insert(20200422, CPhone("David", 20200422));
    myTable2.insert(20200423, CPhone("Mary", 20200423));

    myTable2.dump();
    CPhone aPhone;
    myTable2.lookup(20200421, aPhone);
    cout << aPhone;

    Table <int, CPhone> myTable3;

    myTable2.insert(StringToInt("John"), CPhone("John", 20200421));
    myTable2.insert(StringToInt("David"), CPhone("David", 20200422));
    myTable2.insert(StringToInt("Mary"), CPhone("Mary", 20200423));

    myTable2.dump();
    CPhone aPhone3;
    myTable2.lookup(StringToInt("John"), aPhone3);
    cout << aPhone3;
}

int StringToInt(string strName)
{
    int nSum = 0;
    int nLength = strName.size();
    for (int nIndex = 0; nIndex < nLength; nIndex++)
    {
        nSum += strName.at(nIndex);
    }
    return nSum;
}