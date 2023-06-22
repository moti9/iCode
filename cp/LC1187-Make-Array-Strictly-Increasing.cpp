#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// From N -> 0

class Solution
{
    int countOperations(int ind, int prev, vector<int> &arr, vector<int> &storeArr, unordered_map<int, unordered_map<int, int>> &dp)
    {
        if (ind < 0)
        {
            return 0;
        }

        if (dp.find(ind) != dp.end() && dp[ind].find(prev) != dp[ind].end())
        {
            return dp[ind][prev];
        }
        int change = 1e9 + 7, noChange = 1e9 + 7;
        if (arr[ind] < prev)
        {
            noChange = countOperations(ind - 1, arr[ind], arr, storeArr, dp);
        }
        // For change
        int index = lower_bound(storeArr.begin(), storeArr.end(), prev) - storeArr.begin();
        index -= 1;
        if (index >= 0 && index < storeArr.size())
        {
            int temp = arr[ind];
            arr[ind] = storeArr[index];
            change = 1 + countOperations(ind - 1, arr[ind], arr, storeArr, dp);
            arr[ind] = temp;
        }

        return dp[ind][prev] = min(change, noChange);
    }

public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());

        unordered_map<int, unordered_map<int, int>> dp;

        int ans = countOperations(n - 1, 1e9 + 7, arr1, arr2, dp);
        ans = (ans >= 1e9 + 7) ? -1 : ans;
        return ans;
    }
};

// FROM 0 -> N
/*
class Solution
{
    int countOperations(int ind, int prev, vector<int> &arr, vector<int> &storeArr, unordered_map<int, unordered_map<int, int>> &dp)
    {
        if (ind >= arr.size())
        {
            return 0;
        }

        if (dp.find(ind) != dp.end() && dp[ind].find(prev) != dp[ind].end())
        {
            return dp[ind][prev];
        }
        int change = 1e9 + 7, noChange = 1e9 + 7;
        if (arr[ind] > prev)
        {
            noChange = countOperations(ind + 1, arr[ind], arr, storeArr, dp);
        }
        // For change
        int index = upper_bound(storeArr.begin(), storeArr.end(), prev) - storeArr.begin();
        if (index >= 0 && index < storeArr.size())
        {
            int temp = arr[ind];

            arr[ind] = storeArr[index];
            change = 1 + countOperations(ind + 1, arr[ind], arr, storeArr, dp);
            arr[ind] = temp;
        }

        return dp[ind][prev] = min(change, noChange);
    }

public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());

        unordered_map<int, unordered_map<int, int>> dp;

        int ans = countOperations(0, -1, arr1, arr2, dp);
        ans = (ans >= 1e9 + 7) ? -1 : ans;
        return ans;
    }
};
*/

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    Solution sol;

    cout << sol.makeArrayIncreasing(arr1, arr2) << endl;

    return 0;
}