#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S + N + N + S/2)
// SC- O(N*S)

class Solution
{
public:
    int minSubsetSumDifference(vector<int> &arr, int n)
    {
        int sum = 0;
        for (auto x : arr)
        {
            sum += x;
        }

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int ind = 0; ind < n; ind++)
        {
            dp[ind][0] = true;
        }
        if (arr[0] <= sum)
        {
            dp[0][arr[0]] = true;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= sum; target++)
            {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (arr[ind] <= target)
                {
                    take = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = take || notTake;
            }
        }

        int minDiff = 1e9;
        for (int tar = 0; tar <= sum / 2; tar++)
        {
            if (dp[n - 1][tar] == true)
            {
                int diff = abs((sum - tar) - tar);
                minDiff = min(minDiff, diff);
            }
        }
        return minDiff;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;

    cout << sol.minSubsetSumDifference(arr, n) << endl;

    return 0;
}