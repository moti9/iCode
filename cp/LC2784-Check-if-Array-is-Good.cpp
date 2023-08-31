#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            mp[num] += 1;
        }
        int n = nums.size() - 1;
        for (int i = 1; i < n; i++)
        {
            if (mp[i] != 1)
            {
                return false;
            }
        }
        return mp[n] == 2;
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
    cout << sol.isGood(nums) << endl;

    return 0;
}