#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    bool partitionArr(int ind, int target, vector<int> &arr)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind == 0)
        {
            return target == arr[0];
        }
        bool notTake = partitionArr(ind - 1, target, arr);
        bool take = false;
        if (arr[ind] <= target)
        {
            take = partitionArr(ind - 1, target - arr[ind], arr);
        }
        return take || notTake;
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
        return partitionArr(n - 1, sum / 2, arr);
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