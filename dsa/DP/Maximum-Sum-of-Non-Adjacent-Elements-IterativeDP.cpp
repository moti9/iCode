#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(N)

class Solution
{

public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += dp[i - 2];
            }
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
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
    cout << sol.maximumNonAdjacentSum(nums) << endl;

    return 0;
}