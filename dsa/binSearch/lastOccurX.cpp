/*
Q. Find the last occurrence of X in a
sorted array. If it does not
exits, print —1
A[]= {1, 4, 4, 4, 4, 9, 9, 10,11}

int
ind = upper_bound (a,a+n,X) -a;
ind--;
If (ind>=0 && a[ind]== X) cout << ind;
else
cout<<-1;
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void lastOccurOfX(int A[], int n, int X)
{
    int ind = upper_bound(A, A + n, X) - A;
    ind--;
    if (ind >= 0 && A[ind] == X)
    {
        cout << ind << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    int A[] = {1, 4, 4, 4, 4, 9, 9, 10, 11};
    int n = sizeof(A) / sizeof(A[0]);
    lastOccurOfX(A, n, 2);
    lastOccurOfX(A, n, 4);
    lastOccurOfX(A, n, 9);
    lastOccurOfX(A, n, 12);

    return 0;
}