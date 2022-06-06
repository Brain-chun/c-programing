#include <iostream>

using namespace std;
double FindClosestPoint(double pSample[], int nSizeOfArray, double target, double& nearest);
int FindClosestPoint(int* pSample, int nSizeOfArray, int target, int& nearest, bool bAbsDiff = true);

int main()
{
	const int nSizeOfArray = 5;
	double pSample[nSizeOfArray] = { 0.3,0.6,0.1,0.4,0.8 };
	double  target, nearest, diff;

	cout << "20180622 천범수 input a double number in (0,1.0)" << endl;
	cin >> target;

	diff = FindClosestPoint(pSample, nSizeOfArray, target, nearest);

	cout << "가장 가까운 수는 " << nearest << " 이고 그 숫자와의 차이는 : " << diff << endl;

	int pSampleInt[nSizeOfArray] = { 3,6,1,4,8 };
	int nTarget, nDiff, nNearest;

	cout << "20180622 천범수 input a double number in (0,10)" << endl;
	cin >> nTarget;

	nDiff = FindClosestPoint(pSampleInt, nSizeOfArray, nTarget, nNearest);
	cout << "가장 가까운 수는 " << nNearest << " 이고 그 숫자와의 차이는 : " << nDiff << endl;

}

double FindClosestPoint(double pSample[], int nSizeOfArray, double target, double& nearest)
{
	double mindiff = 1;
	double diff = 1;

	for (int index = 0; index < nSizeOfArray; index++) {
		double val = pSample[index];
		diff = abs(target - val);
		if (diff < mindiff) {
			mindiff = diff;
			nearest = val;
		}
	}
	return mindiff;
}

int FindClosestPoint(int* pSample, int nSizeOfArray, int target, int& nearest, bool bAbsDiff)
{
	int mindiff = 10;
	int diff;

	for (int index = 0; index < nSizeOfArray; index++) {
		int val = pSample[index];
		if (bAbsDiff)
		{
			diff = abs(target - val);
		}
		else
		{
			diff = target - val;
		}
		if (diff < 0)
			continue;
		if (diff < mindiff) 
		{
			mindiff = diff;
			nearest = val;
		}
	}
	return mindiff;
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
