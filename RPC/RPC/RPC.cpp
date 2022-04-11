// RPC.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
int AmIWin(string strUserInput, string strComInput);

int main()
{
	string strUserInput;
	cout << "Hello 20180622 천범수!! Let's play RPS game." << endl;
	cout << "input your choice(R ,P ,S)" << endl;
	cin >> strUserInput;

	int nComInput;
	int nWin = 0;

	srand(time(0));
	nComInput = rand() % 3;

	string strComInput;
	switch (nComInput){
		case 0:
			strComInput = "R";
			break;
		case 1:
			strComInput = "P";
			break;
		case 2:
			strComInput = "S";
			break;
	}
	nWin = AmIWin(strUserInput, strComInput);
	
	cout << "user input is " << strUserInput << "computer choice is " << strComInput << endl;

	string Result;

	switch(nWin)
	{
		case 0:
			Result = " you are draw";
			break;
		case 1:
			Result = "You win";
			break;
		default:
			Result = "You lose";
	}
	cout << Result << endl;

}

int AmIWin(string strUserInput, string strComInput)
{

	int nWin;

	if (strUserInput == strComInput) {
		nWin = 0;
	}
	else {
		if (strUserInput == "R")
		{
			if (strComInput == "P")
			{
				nWin = -1;
			}
			else
			{
				nWin = 1;
			}
		}
		else if (strUserInput == "P")
		{
			if (strComInput == "R")
			{
				nWin = 1;
			}
			else
			{
				nWin = -1;
			}
		}
		else if (strUserInput == "S")
		{
			if (strComInput == "P")
			{
				nWin = -1;
			}
			else
			{
				nWin = 1;
			}
		}
	}
	return nWin;
}