/*
Q. Find the largest number smaller than X in a
sorted array. If it does not
exits, print —1
A[]= {1, 4, 4, 4, 4, 9, 9, 10,11}


ind = lower_bound (a,a+n,X) -a;
ind--;
If (ind>=0) cout << A[ind];
else
cout<<-1;
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void largestNumSmallThanX(int A[], int n, int X)
{
    int ind = lower_bound(A, A + n, X) - A;
    ind--;
    if (ind >= 0)
    {
        cout << A[ind] << endl;
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
    largestNumSmallThanX(A, n, 1);
    largestNumSmallThanX(A, n, 4);
    largestNumSmallThanX(A, n, 9);
    largestNumSmallThanX(A, n, 12);
    largestNumSmallThanX(A, n, 11);

    return 0;
}