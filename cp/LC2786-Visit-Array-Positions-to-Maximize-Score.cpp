#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long long findScore(int i, int j, vector<int> &nums, int x, vector<long long> &dp)
    {
        if (i == nums.size() - 1)
        {
            return nums[i];
        }
    }

public:
    long long maxScore(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<long long> dp(n, -1);
        return findScore(0, 0, nums, x, dp);
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
    int x;
    cin >> x;

    Solution sol;
    cout << sol.maxScore(nums, x);

    return 0;
}