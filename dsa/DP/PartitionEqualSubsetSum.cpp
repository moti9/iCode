#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Space Optimization
bool solve(int n, int k, vector<int> nums)
{
    vector<bool> prev(k + 1, false), curr(k + 1, 0);
    if (nums[0] <= k)
        prev[nums[0]] = true;
    prev[0] = curr[0] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = prev[target];
            bool pick = false;
            if (nums[ind] <= target)
            {
                pick = prev[target - nums[ind]];
            }
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2)
        return false;
    return solve(n, sum / 2, arr);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    cout << canPartition(nums, n);

    return 0;
}