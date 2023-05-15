#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using hashmap
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                return {i, mp[target - nums[i]]};
            }

            mp[nums[i]] = i;
        }
        return {-1, -1};
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
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}