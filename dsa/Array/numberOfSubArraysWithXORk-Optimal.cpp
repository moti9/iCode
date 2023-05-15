#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimized Approach- Using HashMAp
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    int countSubarraysWithXORk(vector<int> &nums, int k)
    {
        int cnt = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int xorr = 0;
        mp[xorr] += 1;

        for (int i = 0; i < n; i++)
        {
            xorr ^= nums[i];
            int xr = xorr ^ k;
            cnt += mp[xr];
            mp[xorr] += 1;
        }
        return cnt;
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
    int k;
    cin >> k;

    Solution sol;
    cout << sol.countSubarraysWithXORk(nums, k) << endl;

    return 0;
}