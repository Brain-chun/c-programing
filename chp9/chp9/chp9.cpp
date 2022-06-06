// chp9.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "hello 20180622 천범수" << endl;
    
    char chString1[30] = "hello", chString2[30];
    /*for (int index = 0; index < 30; index++)
    {
        chString1[index] = 0;
    }
    strcpy_s(chString1, "hello");*/
    strcpy_s(chString2, "Kim");
    /*cout << chString1 << " " << chString2 << endl;
    int nComp;
    if (nComp = strcmp(chString2, chString1))
    {
        cout << nComp << " Two strings are different" << endl;
    }
    else
    {
        cout << nComp << " Two strings are same" << endl;
    }

    cin >> chString2;
    cout << chString2 << endl;

    strcat_s(chString1, chString2);
    cout << chString1 << endl;

    cout << "please enter a sentence with white space" << endl;
    cin.ignore(30, '!');
    cin.getline(chString2, 30);
    cout << chString2 << endl;*/
    string strEx;
    strEx = "How are you?";

    int nLoc;
    //nLoc = strEx.find_first_of("aeiou",0);

    nLoc = strEx.find("are");
    cout << "location of are is " << nLoc << endl;

    strcpy_s(chString1, strEx.c_str());
    cout << chString1 << endl;



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
