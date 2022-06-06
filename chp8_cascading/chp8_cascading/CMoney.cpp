#include "CMoney.h"
#include <iostream>

CMoney::CMoney()
{
	m_nDollar = 0;
	m_nCent = 0;
}

CMoney::CMoney(int nDollar, int nCent)
{
	m_nDollar = nDollar;
	m_nCent = nCent;
}
int CMoney::GetDollar() const
{
	// TODO: 여기에 구현 코드 추가.
	return m_nDollar;
}


void CMoney::SetDollar(int nDollar)
{
	// TODO: 여기에 구현 코드 추가.
	m_nDollar = nDollar;
}


int CMoney::GetCent() const
{
	// TODO: 여기에 구현 코드 추가.
	return m_nCent;
}


void CMoney::SetCent(int nCent)
{
	// TODO: 여기에 구현 코드 추가.
	m_nCent = nCent;
}




//const CMoney CMoney::operator+(CMoney& amount2)
//{
//	int allCents1 = m_nCent + m_nDollar * 100;
//	int allCents2 = amount2.m_nCent + amount2.m_nDollar * 100;
//	int sumAllCents = allCents1 + allCents2;
//	int absAllCents = abs(sumAllCents);
//	int finalDollars = absAllCents / 100;
//	int finalCents = absAllCents % 100;
//
//	if (sumAllCents < 0)
//	{
//		finalDollars = -finalDollars;
//		finalCents = finalCents;
//	}
//	return CMoney(finalDollars, finalCents);
//	
//}
