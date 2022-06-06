#include <iostream>

using namespace std;

void swapElements(int a[], int maxPos, int last); // see Exercise 5-12 
int maxSelect(int a[], int n); // see cx5-4.cpp
void selectionSort(int a[], int n);

void selectionSort(int a[], int n)
{
    int last(n - 1); int maxPos;
    while (last > 0) {
        // invariant: a[last+1] ... a[n-1] is sorted &&
        //		everything in a[0] ... a[last] <= everything in a[last+1] ... a[n-1] 
        maxPos = maxSelect(a, last+1); // last+1 is length from 0 to last 
        swapElements(a, maxPos, last);
        last--;
    }
}
int maxSelect(int a[], int n)
{
    int maxPos(0), currentPos(1);
    while (currentPos < n) {
        // Invariant: a[maxPos] >= a[0] ... a[currentPos-1] 
        if (a[currentPos] < a[maxPos])
        maxPos = currentPos; currentPos++;
    }
    return maxPos;
}

void swapElements(int a[], int maxPos, int last)
{
    int temp(0);
    temp = a[maxPos];
    a[maxPos] = a[last];
    a[last] = temp;
}



int main()
{
    int a[5] = { 3,2,1,6,4 };
    
    cout << "Hello 20180622 천범수" << endl;
    cout << "Before sorting" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    selectionSort(a, 5);
    cout << "Selection sort" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

