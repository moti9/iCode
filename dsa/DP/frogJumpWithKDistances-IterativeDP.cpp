#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(K*N)
// SC- O(N)

class Solution
{
public:
    int frogJumpWithKDistance(int n, int k, vector<int> &heights)
    {
        vector<int> dp(n);
        dp[0] = 0;
        for (int ind = 1; ind < n; ind++)
        {
            int minEng = INT_MAX;
            for (int dist = 1; dist <= k; dist++)
            {
                if (ind - dist >= 0)
                {
                    int jump = dp[ind - dist] + abs(heights[ind] - heights[ind - dist]);
                    minEng = min(minEng, jump);
                }
                else
                {
                    break;
                }
            }

            dp[ind] = minEng;
        }
        return dp[n - 1];
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