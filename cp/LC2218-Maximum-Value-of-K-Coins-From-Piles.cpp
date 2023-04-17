#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    // BOTTOM-UP-APPROACH
    /*
        int maxValueOfCoins(vector<vector<int>> &piles, int k)
        {
            int n = piles.size();
            vector<vector<int>> dp(n + 1, vector<int>(k + 1));
            for (int i = 1; i <= n; i++)
            {
                for (int coins = 0; coins <= k; coins++)
                {
                    int currSum = 0;
                    for (int currCoin = 0; currCoin <= min(coins, (int)piles[i - 1].size()); currCoin++)
                    {
                        if (currCoin > 0)
                        {
                            currSum += piles[i - 1][currCoin - 1];
                        }
                        dp[i][coins] = max(dp[i][coins], dp[i - 1][coins - currCoin] + currSum);
                    }
                }
            }
            return dp[n][k];
        }
    */

    //    TOP-DOWN-APPROACH
    int solve(int i, vector<vector<int>> &piles, int coins, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return 0;
        }
        if (dp[i][coins] != -1)
        {
            return dp[i][coins];
        }
        int currSum = 0;
        for (int currCoin = 0; currCoin <= min(coins, (int)piles[i - 1].size()); currCoin++)
        {
            if (currCoin > 0)
            {
                currSum += piles[i - 1][currCoin - 1];
            }
            dp[i][coins] = max(dp[i][coins], solve(i - 1, piles, coins - currCoin, dp) + currSum);
        }
        return dp[i][coins];
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n, piles, k, dp);
    }
};
int main()
{
    vector<vector<int>> piles;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        vector<int> arr(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[j];
        }
        piles.push_back(arr);
    }
    int k;
    cin >> k;
    Solution sol;
    cout << sol.maxValueOfCoins(piles, k) << endl;

    return 0;
}