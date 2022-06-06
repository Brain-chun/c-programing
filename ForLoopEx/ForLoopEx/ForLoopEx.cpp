// ForLoopEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
using namespace std;
const int NINDEX = 7;
int main()
{
    int pwaiting[NINDEX] = { 19,21,24,20,18,25,23 };
    int nPosMax = 0;
    int nMax = pwaiting[nPosMax];

    for (int index = 0; index < NINDEX; index++)
    {
        if (pwaiting[index] % 2 == 0)
        {
            if (nMax < pwaiting[index])
            {
                nMax = pwaiting[index];
                nPosMax = index;
            }
        }

    }

    cout << nMax << "은 최대값 그때의 배열번호는 " << nPosMax << endl;
    



    //int pwaiting[7] = { 22,21,24,20,18,25,23 };

    //int nMax, nMaxVal, nMaxPos;

    //nMaxPos = 0;
    //nMaxVal = pwaiting[nMaxPos];

    //cout << "20180622 천범수" << endl;
    //for (int nindex = 1; nindex < 7; nindex++)
    //{
    //    int nQurrenVal = pwaiting[nindex];
    //    if (nQurrenVal > nMaxVal) {
    //        nMaxVal = nQurrenVal;
    //        nMaxPos = nindex;
    //    }
    //}

    //cout << "Max value is " << nMaxVal << "\nMaxPos is " << nMaxPos << endl;

    ////짝수중의 최대값 찾기

    //cout << "-------------------------------------------------" << endl;

    //int pWaiting2[7] = { 22,21,24,20,18,25,23 };

    //nMaxPos = -1;
    //nMaxVal = pWaiting2[nMaxPos];

    //for (int nindex = 1; nindex < 7; nindex++)
    //{
    //    int nQurrenVal = pWaiting2[nindex];
    //    if (nQurrenVal % 2 != 0)
    //    {
    //        continue;
    //    }
    //    if (nQurrenVal > nMaxVal) {
    //        nMaxVal = nQurrenVal;
    //        nMaxPos = nindex;
    //    }
    //}

    //cout << "Max value is " << nMaxVal << "\nMaxPos is " << nMaxPos << endl;

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
