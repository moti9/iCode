#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findLenOfLIS(int ind, int prevInd, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (ind == nums.size())
        {
            return 0;
        }
        if (dp[ind][prevInd + 1] != -1)
        {
            return dp[ind][prevInd + 1];
        }

        int len = findLenOfLIS(ind + 1, prevInd, nums, dp);

        if (prevInd == -1 || nums[ind] > nums[prevInd])
        {
            len = max(len, 1 + findLenOfLIS(ind + 1, ind, nums, dp));
        }
        return dp[ind][prevInd + 1] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return findLenOfLIS(0, -1, nums, dp);
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
    cout << sol.lengthOfLIS(nums) << endl;

    return 0;
}