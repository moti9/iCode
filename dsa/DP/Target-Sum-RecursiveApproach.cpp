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
        if (ind == 0)
        {
            if (target == 0 && nums[0] == 0)
            {
                return 2;
            }
            if (target == 0 || target == nums[0])
            {
                return 1;
            }
            return 0;
        }
        int notTake = countWays(ind - 1, target, nums);
        int take = 0;
        if (nums[ind] <= target)
        {
            take = countWays(ind - 1, target - nums[ind], nums);
        }

        return (take + notTake);
    }

public:
    int targetSum(int n, int target, vector<int> &nums)
    {
        int totalSum = 0;
        for (auto num : nums)
        {
            totalSum += num;
        }
        if (totalSum < target)
        {
            return 0;
        }
        if ((totalSum - target) % 2 == 1)
        {
            return 0;
        }

        int newTar = (totalSum - target) / 2;
        return countWays(n - 1, newTar, nums);
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

    int target;
    cin >> target;

    Solution sol;
    cout << sol.targetSum(n, target, nums);

    return 0;
}