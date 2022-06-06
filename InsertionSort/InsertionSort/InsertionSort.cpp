#include <iostream>
#include <stdio.h>

using namespace std;
static int nSize = 10;
void insertNextItem(int a[], int i);
void insertionSort(int a[], int n);

int main()
{
    int n=5;
    cout << "Hello 20180622 천범수" << endl;

    cout << "n 입력" << endl;
    cin >> n;
    int* a;
    a = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << i <<"번째 배열에 값을 입력" << endl;
        cin >> temp;
        a[i] = temp;     
    }
    
    cout << "Before Sorting" << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    insertionSort(a, n);

    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
}
void insertionSort(int a[], int n)
{
    // Precondition: a is an array with subscripts ranging from 0 to  n-1
    int i;
    for (i = 0; i < n; i++)
    //Loop invariant: item in range from 0 to i-1 sorted
        insertNextItem(a, i);
    // Postcondition : array a is sorted
    
}
void insertNextItem(int a[], int i)
{
    // Precondition: array a is sorted from 0 to i-1
    int newItem(a[i]), insertPos(i);
    for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
        // Loop Invariant: newItem <= a[insertPos+1] .. a[i] &&
       //	a[insertPos+1] .. a[i] are sorted  
        a[insertPos] = a[insertPos-1];
        a[insertPos] = newItem;
    // Postcondition: array a is sorted from 0 to i

}
