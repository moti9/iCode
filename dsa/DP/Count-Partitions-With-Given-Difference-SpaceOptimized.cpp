#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S)
// SC- O(S+S)

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
        vector<int> dp(tar + 1, 0);

        if (arr[0] == 0)
            dp[0] = 2;
        else
            dp[0] = 1;

        if (arr[0] != 0 && arr[0] <= tar)
            dp[arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(tar + 1, 0);

            for (int target = 0; target <= tar; target++)
            {

                int notTaken = dp[target];

                int taken = 0;
                if (arr[ind] <= target)
                    taken = dp[target - arr[ind]];

                curr[target] = (notTaken + taken) % mod;
            }
            dp = curr;
        }
        return dp[tar];
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