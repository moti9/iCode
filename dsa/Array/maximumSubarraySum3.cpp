#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(1)

// Kadane's Algorithm
class Solution
{
public:
    int maxSubarraySum(vector<int> &nums)
    {
        int ans = INT_MIN, sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
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