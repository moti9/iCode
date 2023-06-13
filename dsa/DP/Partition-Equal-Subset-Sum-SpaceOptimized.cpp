#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S/2)
// SC- O(S/2 + S/2)

class Solution
{
public:
    bool canPartition(vector<int> &arr, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
            return false;

        int divSum = sum / 2;
        vector<bool> dp(divSum + 1, false);
        dp[0] = true;
        if (arr[0] <= divSum)
        {
            dp[arr[0]] = true;
        }

        for (int ind = n - 2; ind >= 0; ind--)
        {
            vector<bool> curr(divSum + 1, false);
            curr[0] = true;
            for (int target = 1; target <= divSum; target++)
            {
                bool notTake = dp[target];
                bool take = false;
                if (arr[ind] <= target)
                {
                    take = dp[target - arr[ind]];
                }
                curr[target] = take || notTake;
            }
        }

        return dp[divSum];
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
    cout << sol.canPartition(arr, n) << endl;

    return 0;
}