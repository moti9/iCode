#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        int maxLen = 0;
        vector<unordered_map<int, int>> dp(n);
        for (int right = 1; right < n; right++)
        {
            for (int left = 0; left < right; left++)
            {
                int diff = nums[right] - nums[left];
                int len = 1;
                if (dp[left].count(diff) > 0)
                {
                    len = dp[left][diff];
                }
                dp[right][diff] = len + 1;
                maxLen = max(maxLen, dp[right][diff]);
            }
        }
        return maxLen;
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
    cout << sol.longestArithSeqLength(nums) << endl;

    return 0;
}