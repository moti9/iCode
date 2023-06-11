#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int findMaxSum(int ind, vector<int> &nums)
    {
        if (ind < 0)
            return 0;
        if (ind == 0)
            return nums[0];
        int take = nums[ind] + findMaxSum(ind - 2, nums);
        int notTake = findMaxSum(ind - 1, nums);
        return max(take, notTake);
    }

public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();
        return findMaxSum(n - 1, nums);
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