#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int findValueOfPartition(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = 1e9;
        for (int i = 0; i < n - 1; i++)
        {
            int d = nums[i + 1] - nums[i];
            diff = min(diff, d);
        }
        return diff;
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
    cout << sol.findValueOfPartition(nums) << endl;

    return 0;
}