#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    bool getSubset(int ind, int target, vector<int> &nums)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind == 0)
        {
            return target == nums[0];
        }

        bool take = false, notTake;
        if (nums[ind] <= target)
        {
            target -= nums[ind];
            take = getSubset(ind - 1, target, nums);
            target += nums[ind];
        }
        notTake = getSubset(ind - 1, target, nums);

        return take || notTake;
    }

public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        return getSubset(n - 1, k, arr);
    }
};

int main()
{

    return 0;
}