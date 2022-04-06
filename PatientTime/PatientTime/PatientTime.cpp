// PatientTime.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    cout << "20180622 천범수" << endl;
    int numberOfVisits(0), totalWaitingTime(0);
    char answer;
    do {
        bool errorFlag; // arrival, seenByDoctor are instances of Time class 
        Time arrival, seenByDoctor;
        cout << "Enter arrival time:";
        arrival.readTime(errorFlag);
        while (errorFlag) {
            cout << "Arrival time was incorrectly formatted; try again: ";
            arrival.readTime(errorFlag);
        }
        cout << "Enter time seen by doctor:";
        seenByDoctor.readTime(errorFlag); 
        while (errorFlag) {
            cout << "Seen by doctor time was incorrectly formatted; try again: "; seenByDoctor.readTime(errorFlag);
        }
        numberOfVisits++;
        // assume that subtracting one Time from another yields the
        // difference in minutes as an int
        totalWaitingTime += seenByDoctor.subtractTimes(arrival);
        cout << "Done? Enter 'y' to quit, anything else to continue: ";
        cin >> answer;
    } while (answer != 'y');
    cout << "Number of visits: " << numberOfVisits << "\n";
    cout << "Total waiting time: " << totalWaitingTime << " minutes.\n";
    cout << "Average wait is " << totalWaitingTime / numberOfVisits << " minutes.\n";

    int nAvgTime = totalWaitingTime / numberOfVisits;

    Time arrival_new;
    bool errorFlag;
    cout << "Enter your arrival time:";
    arrival_new.readTime(errorFlag);
    int expeceted_time = arrival_new.AddTime(nAvgTime);
    cout << "Your excpected meeting time is ";
    cout << expeceted_time / 60 << ":" << expeceted_time % 60 << endl;



    return 0;



}

