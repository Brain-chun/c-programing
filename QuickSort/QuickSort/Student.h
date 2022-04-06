#include <iostream>
using namespace std;
class Student
{
private:
	int StudentId;

public:	
	Student();
	Student(int ID);
	int GetId() const;
	void showId();
	friend ostream& operator <<(ostream& outputstream, const Student& aStudent);
	friend bool operator<=(const Student& Student1, const Student& Student2);
};

