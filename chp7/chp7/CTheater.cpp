#include "CTheater.h"

int CTheater::m_nNumberOfTheater = 0;

CTheater::CTheater()
{
    m_nNumberOfTheater++;
}
CTheater::CTheater(string strName, int nTripTime, int* pnShowTime, int nSizeOfArray)
{
    m_strName = strName;
    m_nTripTime = nTripTime;
    for (int index = 0; index < nSizeOfArray; index++)
    {
        m_pnShowTime[index] = pnShowTime[index];
    }
    m_nNumberOfTheater++;
}
void CTheater::PrintSchedule()
{
    // TODO: ���⿡ ���� �ڵ� �߰�.
    cout << m_strName << " is " << m_nTripTime << "away" << endl;
    cout << "the schedule is " << endl;
    for (int index = 0; index < 10; index++)
    {
        int nSch = m_pnShowTime[index];
        if (nSch == 0)
        {
            break; 
            cout << nSch << endl;
        }
    }
    cout << endl;
}


void CTheater::InputTheaterInfo(string strName, int nTripTime, int pnShowTime[])
{
    // TODO: ���⿡ ���� �ڵ� �߰�.
    return void();
}


void CTheater::PrintNumberOfTheater()
{
    // TODO: ���⿡ ���� �ڵ� �߰�.
    cout << "number of theater is " << m_nNumberOfTheater << endl;
}
