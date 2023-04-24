/*
Q. Find the smallest number greater than X in a
sorted array. If it does not
exits, print —1
A[]= {1, 4, 4, 4, 4, 9, 9, 10,11}


ind = upper_bound (a,a+n,X) -a;
If (ind<n) cout << A[ind];
else
cout<<-1;
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void smallestNumGreaterThanX(int A[], int n, int X)
{
    int ind = upper_bound(A, A + n, X) - A;
    if (ind < n)
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
    smallestNumGreaterThanX(A, n, 1);
    smallestNumGreaterThanX(A, n, 4);
    smallestNumGreaterThanX(A, n, 9);
    smallestNumGreaterThanX(A, n, 12);
    smallestNumGreaterThanX(A, n, 11);

    return 0;
}