#pragma once
class CMoney
{
	
public:
	
private:
	int m_nCent;
	int m_nDollar;
public:
	CMoney();
	CMoney(int nDollar, int nCent);
	int GetDollar() const;
	void SetDollar(int nDollar);
	int GetCent() const;
	void SetCent(int nCent);
	//const CMoney operator+(CMoney& amount2);
	friend const CMoney operator+(const CMoney& amount1, const CMoney& amount2);
};

 