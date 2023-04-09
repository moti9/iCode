#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long long ans = 0, prefixSum = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            prefixSum += (long long)nums[i];
            ans = max(ans, (prefixSum + i) / (i + 1));
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
    cout << sol.minimizeArrayValue(nums) << endl;

    return 0;
}