#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S)
// SC- O(N*S)

class Solution
{
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totalSum = 0;
        for (auto a : arr)
        {
            totalSum += a;
        }

        if (totalSum < d)
        {
            return 0;
        }
        if ((totalSum - d) % 2 == 1)
        {
            return 0;
        }
        int tar = (totalSum - d) / 2;
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= tar)
            dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= tar; target++)
            {

                int notTaken = dp[ind - 1][target];

                int taken = 0;
                if (arr[ind] <= target)
                    taken = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = (notTaken + taken) % mod;
            }
        }
        return dp[n - 1][tar];
    }
};

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.countPartitions(n, d, arr) << endl;

    return 0;
}