// ArrayHash.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
const int MAX_TABLE = 11;
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
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
