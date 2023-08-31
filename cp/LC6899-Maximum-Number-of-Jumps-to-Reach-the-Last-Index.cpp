#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(nums[i] - nums[j]) <= target)
                {
                    if (dp[j] != -1)
                    {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
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
    cout << sol.maximumJumps(nums, target) << endl;

    return 0;
}