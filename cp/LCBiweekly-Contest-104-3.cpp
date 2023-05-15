#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long maximumOr(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> preSum(n + 1), suffSum(n + 1);
        long long res, pow = 1;

        // Compute 2^k
        for (int i = 0; i < k; i++)
            pow *= 2;

        // Find prefix bitwise OR
        preSum[0] = 0;
        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] | (long long)nums[i];

        // Find suffix bitwise OR
        suffSum[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            suffSum[i] = suffSum[i + 1] | (long long)nums[i];

        // Find maximum OR  value
        res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, preSum[i] | ((long long)nums[i] * pow) | suffSum[i + 1]);

        return res;
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
    int k;
    cin >> k;

    Solution sol;
    cout << sol.maximumOr(nums, k) << endl;

    return 0;
}
