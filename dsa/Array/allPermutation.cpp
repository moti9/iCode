#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            solve(index + 1, nums, ans);
            swap(nums[i], nums[index]);
        }
    }

private:
public:
    void printAllPermutation(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        for (auto n : ans)
        {
            for (auto a : n)
                cout << a << " ";
            cout << endl;
        }
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
    sol.printAllPermutation(nums);
    // for (auto n : nums)
    //     cout << n << " ";
    // cout << endl;
    return 0;
}