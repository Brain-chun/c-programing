#pragma once
#include <string>
using namespace std;

class CPhone
{
public:
	CPhone();
	CPhone(string strName, int nBirth);
private:
	int m_nBirth;
	string m_strName;
public:
	string GetName();
	int GetBirth();
	void setName(string strName);
	void SetBirth(int nBirth);
	friend ostream& operator<<(ostream& outstream, const CPhone& aPhone);
};

