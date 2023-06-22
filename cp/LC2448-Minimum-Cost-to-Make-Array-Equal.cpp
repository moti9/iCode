#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long long findCost(vector<int> &nums, vector<int> &cost, int target)
    {
        long long totalCost = 0;
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            totalCost += (long long)abs(target - nums[left]) * (long long)cost[left];
            totalCost += (long long)abs(target - nums[right]) * (long long)cost[right];
            left += 1;
            right -= 1;
        }
        if (n & 1)
        {
            totalCost += (long long)abs(target - nums[n / 2]) * (long long)cost[n / 2];
        }
        return totalCost;
    }

public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {

        int left = 0, right = 1e6 + 1;
        // for(int i=0;i < nums.size(); i++){
        //     left = min(left, nums[i]);
        //     right = max(right, nums[i]);
        // }
        long long minCost = 1e15;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long curr_cost = findCost(nums, cost, mid);
            long long right_cost = findCost(nums, cost, mid + 1);

            minCost = min(curr_cost, right_cost);
            if (right_cost > curr_cost)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return minCost;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    Solution sol;
    cout << sol.minCost(nums, cost) << endl;

    return 0;
}