#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findMaxSumOfParts(int i, int n, vector<int> &arr, int k)
    {
        if (i == n)
        {
            return 0;
        }

        int maxSum = 0;
        int maxi = 0, len = 0;

        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);

            int sum = len * maxi + findMaxSumOfParts(j + 1, n, arr, k);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        return findMaxSumOfParts(0, n, arr, k);
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