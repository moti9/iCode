#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int collectCoins(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int maxCoin = 0;
        for (int ind = i; ind <= j; ind++)
        {
            int coins = nums[i - 1] * nums[ind] * nums[j + 1] + collectCoins(i, ind - 1, nums, dp) + collectCoins(ind + 1, j, nums, dp);
            maxCoin = max(maxCoin, coins);
        }
        return dp[i][j] = maxCoin;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return collectCoins(1, n, nums, dp);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.maxCoins(nums) << endl;

    return 0;
}