#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(N+N)

class Solution
{
    int findSteps(int ind, vector<int> &dp)
    {
        if (ind == 0 || ind == 1)
        {
            return 1;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        return dp[ind] = findSteps(ind - 1, dp) + findSteps(ind - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return findSteps(n, dp);
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.climbStairs(n) << endl;

    return 0;
}