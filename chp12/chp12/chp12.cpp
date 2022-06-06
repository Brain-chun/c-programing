// chp12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;
    cout << "hello 20180622 천범수" << endl;

    int nSize = 100;
    int* pnData;
    pnData = new int[nSize];

    inStream.open("infile.txt");
    if (inStream.fail())
    {
        cout << "file open failed\n";
        exit(1);
    }
    outStream.open("outfile.txt",ios::app);

    /*int first, second, third;
    inStream >> first >> second >> third;
    outStream << "The sum of the first 3\n"
        << "numers in the infile.txt\n"
        << "is" << first + second + third << endl;*/
    int nCnt = 0;
    while (!inStream.eof())
    {
        inStream >> pnData[nCnt];
        cout << pnData[nCnt] << " ";
        nCnt++;
    }
    int nSum = 0;
    for (int index = 0; index < nCnt; index++)
    {
        nSum += pnData[index];
    }
    //outfile.txt에 기록(append)
    outStream << "THe sum of " << nCnt
        << "number is in the infile\n"
        << " is " << nSum << endl;

    inStream.close();
    outStream.close();

    return 0;
}

