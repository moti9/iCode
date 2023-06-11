#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(K*N)
// SC- O(N+N)

class Solution
{
    int findMinEnergy(int ind, int k, vector<int> &heights, vector<int> &dp)
    {
        if (ind == 0)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int minEng = INT_MAX;

        for (int dist = 1; dist <= k; dist++)
        {
            if (ind - dist >= 0)
            {
                int jump = findMinEnergy(ind - dist, k, heights, dp) + abs(heights[ind] - heights[ind - dist]);
                minEng = min(minEng, jump);
            }
            else
            {
                break;
            }
        }

        return dp[ind] = minEng;
    }

public:
    int frogJumpWithKDistance(int n, int k, vector<int> &heights)
    {
        vector<int> dp(n, -1);
        return findMinEnergy(n - 1, k, heights, dp);
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    Solution sol;
    cout << sol.frogJumpWithKDistance(n, k, heights) << endl;

    return 0;
}