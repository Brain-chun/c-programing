// practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;


int main()
{
	int pWaiting[7] = { 22, 21, 24, 20, 18, 25, 23 };

	int nPosMax = 0;
	int nMax = pWaiting[nPosMax];

	for (int index = 0; index < 7; index++)
	{
		if (pWaiting[index] > nMax)
		{
			nMax = pWaiting[index];
			nPosMax = index;
		}
	}
	cout << "hell0 20180622 천범수" << endl;
	cout << "최대값은 " << nMax << "이고 그때의 배열 위치는 " << nPosMax << "입니다." << endl;

	cout << "----------------짝수중의최대값구하기--------------------" << endl;


	int pWaiting2[7] = { 22, 21, 24, 20, 18, 25, 23 };

	int nPosMax2 = 0;
	int nMax2 = pWaiting2[nPosMax2];

	for (int index = 0; index < 7; index++)
	{
		if (pWaiting2[index] % 2 == 0)
		{
			if (pWaiting2[index] > nMax2)
			{
				nMax2 = pWaiting2[index];
				nPosMax2 = index;
			}
		}
		else
		{
			continue;
		}
	}
	cout << "최대값은 " << nMax2 << "이고 그때의 배열 위치는 " << nPosMax2 << "입니다." << endl;
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
