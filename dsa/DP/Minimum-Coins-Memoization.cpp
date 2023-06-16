#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*E)
// SC- O(E + N*E)

class Solution
{
    int countElements(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if ((target % nums[0]) == 0)
            {
                return (target / nums[0]);
            }
            return 1e9;
        }

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        int notTake = countElements(ind - 1, target, nums, dp);
        int take = 1e9;
        if (nums[ind] <= target)
        {
            take = 1 + countElements(ind, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = min(take, notTake);
    }

public:
    int minimumElements(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(x + 1, -1));
        int minEle = countElements(n - 1, x, nums, dp);

        return minEle >= 1e9 ? -1 : minEle;
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
    int x;
    cin >> x;

    Solution sol;
    cout << sol.minimumElements(nums, x);

    return 0;
}