#pragma once
#include<iostream>
#include <string>

using namespace std;

class CTheater
{
	
	int m_nTripTime;
	int m_pnShowTime[10];
	string m_strName;
	static int m_nNumberOfTheater;
public:
	void PrintSchedule();
	void InputTheaterInfo(string strName, int nTripTime, int pnShowTime[]);
	CTheater();
	CTheater(string strName, int nTripTime, int* pnShowTime, int nSizeOfArray);

	static void PrintNumberOfTheater();
};

