#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(NlogN+N)
// SC- O(1)
// Using sort
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}