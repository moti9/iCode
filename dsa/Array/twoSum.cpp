#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Brute force- Nested Loop
// TC- O(N*N)
// SC- O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
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
    int target;
    cin >> target;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}