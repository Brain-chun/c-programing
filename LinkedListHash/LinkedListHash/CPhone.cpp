#include "CPhone.h"
#include <iostream>
using namespace std;

CPhone::CPhone()
{

}

CPhone::CPhone(string strName, int nBirth)
{
	m_strName = strName;
	m_nBirth = nBirth;
}

string CPhone::GetName()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_strName;
}


int CPhone::GetBirth()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return m_nBirth;
}


void CPhone::setName(string strName)
{
	m_strName = strName;
}


void CPhone::SetBirth(int nBirth)
{
	m_nBirth = nBirth;
}