// selection sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
using namespace std;

void fillArray(int *a, int size, int& numberUsed);
void sort(int *a, int numberUsed);
void swapValues(int& v1, int& v2);
int indexOfSmallest(const int *a, int startindex, int numberUsed);

const int NSIZE = 10;

int main()
{
    cout << "hello 20180622 천범수 \nThis is Sorting program" << endl;

    int sampleArray[NSIZE], numberUsed;
    fillArray(sampleArray, NSIZE ,numberUsed);
    sort(sampleArray, numberUsed);

    cout << "Sorting result" << endl;
    for (int index = 0; index < numberUsed; index++) 
        cout << sampleArray[index] << " ";
    cout << endl;
    
    return 0;
}

void fillArray(int *a, int size, int& numberUsed) 
{
    cout << "enter up to" << size << " nonnegative whole numbers\n"
         << "mark the end of list with a negative number" <<endl;
    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }
    numberUsed = index;
}

void sort(int *a, int numberUsed) 
{
    int indexOfNextSmallest;
    for (int index = 0; index < numberUsed - 1; index++)
    {
        indexOfNextSmallest = indexOfSmallest(a, index, numberUsed);
        swapValues(a[index], a[indexOfNextSmallest]);
    }
}

void swapValues(int& v1, int& v2) 
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int indexOfSmallest(const int *a, int startindex, int numberUsed)
{
    int min = a[startindex], indexOfMin = startindex;
    for (int index = startindex+1; index < numberUsed; index++)
        if (a[index] < min)
        {
            min = a[index];
            indexOfMin = index;
        }
    return indexOfMin;
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
