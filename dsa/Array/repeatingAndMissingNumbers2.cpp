#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Maths
// TC- O(N)
// SC- O(1)

class Solution
{
public:
    vector<int> findRepeatingMissingNum(vector<int> &nums)
    {
        ll n = nums.size();
        ll sum = (n * (n + 1)) / 2;
        ll prod = (n * (n + 1) * (2 * n + 1)) / 6;
        for (ll i = 0; i < n; i++)
        {
            sum -= (ll)nums[i];
            prod -= (ll)nums[i] * (ll)nums[i];
        }
        vector<int> ans;
        ll missingNum = (sum + prod / sum) / 2;
        ll repeatingNum = missingNum - sum;
        ans.push_back(missingNum);
        ans.push_back(repeatingNum);
        return ans;
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
    vector<int> ans = sol.findRepeatingMissingNum(nums);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}