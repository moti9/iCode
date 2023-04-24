#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// void solve(int ind, int n, vector<int> nums, vector<int> ds, int &ans)
// void solve(int ind, int n, vector<int> nums, vector<int> ds, vector<vector<int>> &ans)
// {
//     if (ind == n)
//     {
//         // int sz = ds.size();
//         // ans = max(ans, sz);
//         ans.push_back(ds);
//         return;
//     }
//     // for (int i = ind; i < n; i++)
//     // {
//     if (ds.size() == 0)
//     {
//         ds.push_back(nums[ind]);
//         solve(ind + 1, n, nums, ds, ans);
//         ds.pop_back();
//     }
//     else
//     {
//         int temp = ds.back();
//         if (nums[ind] % temp == 0 && nums[ind] / temp == temp)
//         {
//             ds.push_back(nums[ind]);
//             solve(ind + 1, n, nums, ds, ans);
//             ds.pop_back();
//         }
//     }
//     solve(ind + 1, n, nums, ds, ans);
//     // }
// }

int longestSquareStreak(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto x : nums)
    {
        mp[x]++;
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    // vector<int> ds;
    // vector<vector<int>> ans;
    // solve(0, nums.size(), nums, ds, ans);

    for (auto x : nums)
    {
        int temp = x;
        int ct = 0;
        while (mp[temp])
        {
            ct += 1;
            temp = temp * temp;
        }
        ans = max(ans, ct);
    }

    if (ans < 2)
    {
        return -1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << longestSquareStreak(nums) << endl;

    return 0;
}