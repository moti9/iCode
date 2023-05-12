#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Space Optimization
// TC- O(N1*N2)
// SC- O(2*N2)

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m), prev(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[j] = 1;
                    if (j > 0)
                        dp[j] += prev[j - 1];
                }
                else
                {
                    if (i > 0)
                        dp[j] = max(dp[j], prev[j]);
                    if (j > 0)
                        dp[j] = max(dp[j], dp[j - 1]);
                }
            }
            prev = dp;
        }
        return dp[m - 1];
    }
};

// Iterative DP
// TC- O(N1*N2)
// SC- O(N1*N2)
/*
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = max(dp[i][j], 1);
                    if (i > 0 && j > 0)
                        dp[i][j] += dp[i - 1][j - 1];
                }
                else
                {
                    if (i > 0)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    if (j > 0)
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
*/

// Memoization
// TC- O(N1*N2)
// SC- O(N1*N2)-dp+ O(N1+N2)-rec..stack
/*
class Solution
{
    int solve(int idx1, int idx2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 || idx2 < 0)
        {
            return 0;
        }
        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }

        int cntline = 0;
        if (nums1[idx1] == nums2[idx2])
        {
            cntline = max(cntline, 1 + solve(idx1 - 1, idx2 - 1, nums1, nums2, dp));
        }
        cntline = max(cntline, solve(idx1 - 1, idx2, nums1, nums2, dp));
        cntline = max(cntline, solve(idx1, idx2 - 1, nums1, nums2, dp));
        return dp[idx1][idx2] = cntline;
    }

public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, nums1, nums2, dp);
    }
};
*/

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    int m;
    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }

    Solution sol;
    cout << sol.maxUncrossedLines(nums1, nums2) << endl;

    return 0;
}