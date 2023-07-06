#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxLen = 1;

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[ind] > nums[prev])
                {
                    if (dp[prev] + 1 > dp[ind])
                    {
                        dp[ind] = 1 + dp[ind];
                        cnt[ind] = cnt[prev];
                    }
                    else if (dp[prev] + 1 == dp[ind])
                    {
                        cnt[ind] += cnt[prev];
                    }
                }
            }
            if (dp[ind] > maxLen)
            {
                maxLen = dp[ind];
            }
        }

        int cntLIS = 0;

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLen)
            {
                cntLIS += cnt[i];
            }
        }

        return cntLIS;
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
    cout << sol.findNumberOfLIS(nums) << endl;

    return 0;
}