#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(1)
class Solution
{
public:
    int maxSubarraySum(vector<int> &nums)
    {
        int ans = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                ans = max(ans, sum);
            }
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
    cout << sol.maxSubarraySum(nums) << endl;
    return 0;
}