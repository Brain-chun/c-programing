#include "CDyna.h"

#include<iostream>
using namespace std;

void CDyna::ShowSchedule()
{
	// TODO: 여기에 구현 코드 추가.
	if (m_pnSchedule != NULL)
	{
		for (int index = 0; index < m_nSize; index++)
		{
			cout << m_pnSchedule[index] << endl;
		}
	}
}

CDyna::CDyna()
{
	m_nSize = 0;
	m_pnSchedule = NULL;
}

CDyna::~CDyna()
{
	if (m_pnSchedule != NULL)
	{
		delete m_pnSchedule;
	}
}

void CDyna::SetInfo(int nSize, int* pSch)
{
	// TODO: 여기에 구현 코드 추가.
	m_nSize = nSize;
	if (m_pnSchedule != NULL) {
		delete[] m_pnSchedule;
	}
	m_pnSchedule = new int[m_nSize];
	for (int index = 0; index < nSize; index++)
	{
		m_pnSchedule[index] = pSch[index];
	}
}

CDyna& CDyna::operator=(const CDyna& rtSide)
{
	if (this == &rtSide)
	{
		return *this;
	}
	else
	{
		m_nSize = rtSide.m_nSize;
		if (m_pnSchedule != NULL)
		{
			delete[] m_pnSchedule;
		}
		m_pnSchedule = new int[m_nSize];
		for (int index = 0; index < m_nSize; index++)
		{
			m_pnSchedule[index] = rtSide.m_pnSchedule[index];
		}
		return *this;
	}
}

