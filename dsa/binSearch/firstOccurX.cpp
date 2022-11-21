/*
Q. Find the first occurrence of X in a
sorted array. If it does not
exits, print —1
A[]= {1, 4, 4, 4, 4, 9, 9, 10,11}

int
ind = lower_bound (a,a+n,X) -a;
If (ind != N && a[ind]== X) cout << ind;
else
cout<<-1;
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void firstOccurOfX(int A[], int n, int X)
{
    int ind = lower_bound(A, A + n, X) - A;
    if (ind != n && A[ind]==X)
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
    firstOccurOfX(A,n,2);
    firstOccurOfX(A,n,4);
    firstOccurOfX(A,n,9);
    firstOccurOfX(A,n,12);

    return 0;
}