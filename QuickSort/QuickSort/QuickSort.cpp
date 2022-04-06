#include <iostream>
#include <string>
#include "Student.h"

using namespace std;
using std::string;

template<typename T>
void swapElements(T a[], int first, int last); 
template<typename T>
int partition(T a[], int first, int last);
template<typename T>
void quicksort(T a[], int first, int last);
template<typename T>
void showValues(T a[]);

int nSize = 7;

int main()
{
    cout << "Hello 20180622 천범수" << endl;
    cout << endl;

    char a[] = { 'b','g','e','f','c','d','a' };
    int b[] = { 67,58,38,81,90,57,54 };
    double c[] = { 67.1,58.1,38.1,81.1,90.1,57.1,54.1 };
    
    cout << "Before Sorting" << endl;
    showValues(a);
    quicksort(a, 0, nSize - 1);//template character array quick sort
    cout << "After Char Sorting" << endl;
    showValues(a);
    cout << endl;

    cout << "Before Sorting" << endl;
    showValues(b);
    quicksort(b, 0, nSize - 1);//template integer array quick sort
    cout << "After Int Sorting" << endl;
    showValues(b);
    cout << endl;

    cout << "Before Sorting" << endl;
    showValues(c);
    quicksort(c, 0, nSize - 1);//template double array quick sort
    cout << "After Double Sorting" << endl;
    showValues(c);
    cout << endl;

    Student Student1(20180622);
    Student Student2(20180407);
    Student Student3(20160824);
    Student Student4(20210628);
    Student Student5(20202274);
    Student Student6(20180462);
    Student Student7(20210846);

    Student d[7] = { Student1,Student2 ,Student3,Student4,Student5,Student6,Student7 };

    cout << "Before Sorting" << endl;
    showValues(d);
    quicksort(d, 0, nSize - 1);//template Class array quick sort
    cout << "After Class Sorting" << endl;
    showValues(d);
   
    cout << endl;

}

ostream& operator << (ostream& outputstream, const Student& aStudent)
{
    
    outputstream << aStudent.StudentId;

    return outputstream;
}

bool operator<=(const Student& Student1, const Student& Student2)
{
    
    if (Student1.GetId() <= Student2.GetId()) {
        return true;
    }        
    else
        return false;
}

template<typename T>
void quicksort(T a[], int first, int last)
{
    // precondition: a is an array;
    //	The portion to be sorted runs from index first to index last inclusive.
    if (first >= last) // Base Case -- nothing to sort, so just return
        return;
    // Otherwise, we’re in the recursive case.
    // The partition function uses the item in a[first] as the pivot
    // and returns the position of the pivot -- split -- after the partition.
    int split(partition(a, first, last));


    // Recursively, sort the two partitions. 
    quicksort(a, first, split-1);
    quicksort(a, split+1, last);
    // postcondition: a is sorted in ascending order
    // between first and last inclusive.
}

template<typename T>
int partition(T a[], int first, int last)
{
    int lastSmall(first), i;

    for (i = first + 1; i <= last; i++)
        // loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
        //	a[lastSmall+1]...a[i-1] > a[first]
        if (a[i] <= a[first]) { // key comparison
            ++lastSmall; swapElements(a, lastSmall, i);
        }


    swapElements(a, first, lastSmall); // put pivot into correct position
    // postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
    //	a[lastSmall+1]...a[last] > a[lastSmall]
    return lastSmall; // this is the final position of the pivot -- the split index
}

template<typename T>
void swapElements(T a[], int first, int last)
{
    T temp;
    temp = a[first];
    a[first] = a[last];
    a[last] = temp;

}

template<typename T>
void showValues(T a[])
{
    //int size = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < nSize; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}