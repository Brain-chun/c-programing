#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	StudentId = 0;
}

Student::Student(int ID)
{
	StudentId = ID;
}

int Student::GetId() const
{
	return StudentId;
}

void Student::showId()
{
	cout << StudentId << endl;
}
