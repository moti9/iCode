#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    void solve(int ind, int n, vector<int> &nums, set<vector<int>> &st, vector<int> ds)
    {
        if (ind >= n)
        {
            st.insert(ds);
            return;
        }
        if (ds.size() < 1 || ds.back() <= nums[ind])
        {
            ds.push_back(nums[ind]);
            solve(ind + 1, n, nums, st, ds);
            ds.pop_back();
        }
        solve(ind + 1, n, nums, st, ds);
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        set<vector<int>> st;
        int n = nums.size();
        vector<int> ds;
        solve(0, n, nums, st, ds);
        vector<vector<int>> ans;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> ans = sol.findSubsequences(nums);
    for (auto arr : ans)
    {
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}