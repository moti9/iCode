#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Iterative DP
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    int findNthFibonacciNumber(int n)
    {
        vector<int> dp(n + 1, 0); // step-1 -> declare dp
        // step-2 -> base case
        dp[0] = 0, dp[1] = 1;
        // step-3 -> do stuffs
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
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