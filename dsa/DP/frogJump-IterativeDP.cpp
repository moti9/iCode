#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(N)

class Solution
{
public:
    int frogJump(int n, vector<int> &heights)
    {
        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n - 1];
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