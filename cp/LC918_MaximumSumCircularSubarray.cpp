#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = 0, currMax = 0, currMin = 0, maxSum = INT_MIN, minSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
            currMax += nums[i];
            currMin += nums[i];
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
            if (currMax < 0)
                currMax = 0;
            if (currMin > 0)
                currMin = 0;
        }

        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
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
    cout << sol.maxSubarraySumCircular(nums) << endl;

    return 0;
}