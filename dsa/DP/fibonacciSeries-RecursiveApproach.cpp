#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
// TC- O(2^N)
// SC- O(N)

class Solution
{
    int fibseries(int ind)
    {
        if (ind <= 1)
        {
            return ind;
        }
        return fibseries(ind - 1) + fibseries(ind - 2);
    }

public:
    // Recursive
    int findNthFibonacciNumber(int n)
    {
        return fibseries(n);
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.findNthFibonacciNumber(n) << endl;

    return 0;
}