#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^E)
// SC- O(E)

class Solution
{
    int countElements(int ind, int target, vector<int> &nums)
    {
        if (ind == 0)
        {
            if ((target % nums[0]) == 0)
            {
                return (target / nums[0]);
            }
            return 1e9;
        }

        int notTake = countElements(ind - 1, target, nums);
        int take = 1e9;
        if (nums[ind] <= target)
        {
            take = 1 + countElements(ind, target - nums[ind], nums);
        }
        return min(take, notTake);
    }

public:
    int minimumElements(vector<int> &nums, int x)
    {
        int n = nums.size();
        int minEle = countElements(n - 1, x, nums);

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