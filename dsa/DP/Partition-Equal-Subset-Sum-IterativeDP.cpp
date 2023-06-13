#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S/2)
// SC- O(N*S/2)

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
        vector<vector<bool>> dp(n, vector<bool>(divSum + 1, false));
        for (int ind = 0; ind < n; ind++)
        {
            dp[ind][0] = true;
        }
        if (arr[0] <= divSum)
        {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= divSum; target++)
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

        return dp[n - 1][divSum];
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