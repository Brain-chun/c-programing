#pragma once

class CDyna
{
private:
	int m_nSize;
	int* m_pnSchedule;

public:

	CDyna();
	~CDyna();
	CDyna& operator=(const CDyna& rtSide);
	void ShowSchedule();
	void SetInfo(int nSize, int* pSch);
};

