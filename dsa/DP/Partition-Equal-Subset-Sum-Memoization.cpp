#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S/2)
// SC- O(N*S/2 + N)

class Solution
{
    bool partitionArr(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        if (ind == 0)
        {
            return target == arr[0];
        }
        bool notTake = partitionArr(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
        {
            take = partitionArr(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || notTake;
    }

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
        vector<vector<int>> dp(n, vector<int>(divSum + 1, -1));
        return partitionArr(n - 1, sum / 2, arr, dp);
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