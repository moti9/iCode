#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findMinDiff(int ind, int totalSum, int sum, vector<int> &arr)
    {
        if (ind == 0)
        {
            return abs((totalSum - sum) - sum);
        }
        int notTake = findMinDiff(ind - 1, totalSum, sum, arr);
        int take = findMinDiff(ind - 1, totalSum, sum + arr[ind], arr);
        return min(take, notTake);
    }

public:
    int minSubsetSumDifference(vector<int> &arr, int n)
    {
        int sum = 0;
        for (auto x : arr)
            sum += x;

        return findMinDiff(n - 1, sum, 0, arr);
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