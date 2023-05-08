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
    vector<int> nextPermutation(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        int i = 0;
        for (; i < ans.size(); i++)
            if (ans[i] == nums)
                break;
        if (i < nums.size() - 1)
            return ans[i + 1];
        return nums;
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
    vector<int> ans = sol.nextPermutation(nums);
    for (auto a : ans)
        cout << a << " ";
    cout << "\n";

    return 0;
}