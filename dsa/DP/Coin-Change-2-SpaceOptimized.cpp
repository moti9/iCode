#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*V)
// SC- O(V + V)

class Solution
{

public:
    long countWaysToMakeChange(vector<int> &arr, int n, int value)
    {
        vector<long> dp(value + 1);
        for (int tar = 0; tar <= value; tar++)
        {
            if (tar % arr[0] == 0)
            {
                dp[tar] = 1;
            }
        }
        for (int ind = 1; ind < n; ind++)
        {
            vector<long> curr(value + 1);
            for (int target = 0; target <= value; target++)
            {
                long notTake = dp[target];
                long take = 0;
                if (arr[ind] <= target)
                {
                    take = curr[target - arr[ind]];
                }
                curr[target] = (take + notTake);
            }
            dp = curr;
        }
        return dp[value];
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

    int value;
    cin >> value;

    Solution sol;
    cout << sol.countWaysToMakeChange(arr, n, value) << endl;

    return 0;
}