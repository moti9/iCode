#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int md = 1e9 + 7;

public:
    int sumOfPower(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long curr = 0;
        for (auto x : nums)
        {
            long long cr = (curr + x) * x % md;
            cr = cr * x % md;
            ans = (ans + cr) % md;
            curr = curr * 2 % md;
            curr = (curr + x) % md;
        }
        return (int)ans;
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
    cout << sol.sumOfPower(nums) << endl;

    return 0;
}