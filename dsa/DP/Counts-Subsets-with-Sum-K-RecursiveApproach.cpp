#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int countWays(int ind, int target, vector<int> &nums)
    {
        if (target == 0)
        {
            return 1;
        }
        if (ind == 0)
        {
            return target == nums[0];
        }
        int notTake = countWays(ind - 1, target, nums);
        int take = 0;
        if (nums[ind] <= target)
        {
            take = countWays(ind - 1, target - nums[ind], nums);
        }
        return take + notTake;
    }

public:
    int findWays(vector<int> &nums, int tar)
    {
        int n = nums.size();
        return countWays(n - 1, tar, nums);
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

    int tar;
    cin >> tar;

    Solution sol;
    cout << sol.findWays(nums, tar) << endl;

    return 0;
}