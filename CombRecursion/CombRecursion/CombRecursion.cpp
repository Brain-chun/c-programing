#include <iostream>

using namespace std;

int choose(int n, int k);
int nCnt(0);

int main()
{
    int n, k;
    cout << "Hello 20180622 천범수" << endl;
    cout << "input n : ";
    cin >> n;
    cout << "input k : ";
    cin >> k;

    cout << "The value of n Combination k is " << choose(n, k) << endl;
    cout << "Total call of choose function is " << nCnt << endl;
}

int choose(int n, int k)
{
    nCnt++;

    if (k == 1)
        return n;

    else if (n == k)
        return 1;

    else//recursive case : n > k and k > 1
        return choose(n - 1, k - 1) + choose(n - 1, k);
}