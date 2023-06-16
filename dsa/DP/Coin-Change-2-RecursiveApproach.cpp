#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    long countWays(int ind, int target, vector<int> &arr)
    {
        if (ind == 0)
        {
            if (target % arr[0] == 0)
            {
                return 1;
            }
            return 0;
        }
        long notTake = countWays(ind - 1, target, arr);
        long take = 0;
        if (arr[ind] <= target)
        {
            take = countWays(ind, target - arr[ind], arr);
        }
        return (take + notTake);
    }

public:
    long countWaysToMakeChange(vector<int> &arr, int n, int value)
    {
        return countWays(n - 1, value, arr);
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