#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        long long ct = 0;
        int leftBound = -1;
        int lastMin = -1, lastMax = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= minK && nums[i] <= maxK)
            {
                lastMin = (nums[i] == minK) ? i : lastMin;
                lastMax = (nums[i] == maxK) ? i : lastMax;
                ct += max(0, min(lastMin, lastMax) - leftBound);
            }
            else
            {
                leftBound = i;
                lastMin = -1;
                lastMax = -1;
            }
        }
        return ct;
    }
};

// Geedy Approach(Generate all possible subarray and co)

long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    int n = nums.size();
    long long ct = 0;
    for (int i = 0; i < n; i++)
    {
        int mini = 1e7;
        int maxi = 0;
        for (int j = i; j < n; j++)
        {
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);

            if (mini == minK && maxi == maxK)
            {
                ct += 1;
            }
        }
    }
    return ct;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int minK, maxK;
    cin >> minK >> maxK;

    Solution sol;
    cout << sol.countSubarrays(nums, minK, maxK) << endl;

    return 0;
}