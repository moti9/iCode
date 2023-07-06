#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int maxSum = 0;
            int maxi = 0, len = 0;

            for (int j = i; j < min(n, i + k); j++)
            {
                len++;
                maxi = max(maxi, arr[j]);

                int sum = len * maxi + dp[j + 1];
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
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

    int k;
    cin >> k;

    Solution sol;
    cout << sol.maxSumAfterPartitioning(arr, k);

    return 0;
}