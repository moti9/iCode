#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// You are given an array 'A' of length 'N'. Three consecutive elements are considered the 'secret code' if their sum is divisible by '10'.

// Return '1' if the array contains the 'secret code' and return '0' otherwise.

int containsSecretCode(const std::vector<int> &A)
{
    for (int i = 0; i < A.size() - 2; ++i)
    {
        if ((A[i] + A[i + 1] + A[i + 2]) % 10 == 0)
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << containsSecretCode(arr);

    return 0;
}