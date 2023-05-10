#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Count Sort
// TC- O(N+N)
// SC- O(N)

class Solution
{
public:
    vector<int> findRepeatingMissingNum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n + 1);
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]] += 1;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (freq[i] == 0 || freq[i] == 2)
            {
                ans.push_back(i);
            }
        }
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