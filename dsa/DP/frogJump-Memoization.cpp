#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(N+N)

class Solution
{
    int findMinEnergy(int ind, vector<int> &heights, vector<int> &dp)
    {
        if (ind == 0)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int left = findMinEnergy(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
        int right = INT_MAX;
        if (ind > 1)
            right = findMinEnergy(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
        return dp[ind] = min(left, right);
    }

public:
    int frogJump(int n, vector<int> &heights)
    {
        vector<int> dp(n, -1);
        return findMinEnergy(n - 1, heights, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    Solution sol;
    cout << sol.frogJump(n, heights) << endl;

    return 0;
}