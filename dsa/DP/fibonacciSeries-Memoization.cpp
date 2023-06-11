#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive DP (Memoization)
// TC- O(N)
// SC- O(N+N)

class Solution
{
    int fibseries(int ind, vector<int> &dp)
    {
        if (ind == 0 || ind == 1)
        {
            return ind;
        }
        // step-3 -> check already solved or not
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        return dp[ind] = fibseries(ind - 1, dp) + fibseries(ind - 2, dp); // step -2 -> store
    }

public:
    int findNthFibonacciNumber(int n)
    {
        vector<int> dp(n + 1, -1); // step-1 -> declare dp
        return fibseries(n, dp);
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