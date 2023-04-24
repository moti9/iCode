#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// class Solution
// {
// public:
//     vector<int> shuffle(vector<int> &nums, int n)
//     {
//         vector<int> ans;
//         for (int i = 0; i < n; i++)
//         {
//             ans.push_back(nums[i]);
//             ans.push_back(nums[n + i]);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int j = n;
        for (int i = 1; i <= 2 * n; i += 2, j += 2)
        {
            nums.insert(nums.begin() + i, nums[j]);
        }

        nums.resize(2 * n);

        return nums;
    }
};

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[n + i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    vector<int> ans = sol.shuffle(nums, n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}