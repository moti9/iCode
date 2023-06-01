#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void solve(int i, vector<int> &nums, vector<int> &arr, long long &ans)
    {
        if (i >= nums.size())
        {
            int n = arr.size();
            if (n == 0)
            {
                return;
            }
            long long temp = 1;
            for (int i = 0; i < n; i++)
            {
                temp *= (long long)arr[i];
            }
            ans = max(ans, temp);
            return;
        }
        arr.push_back(nums[i]);
        solve(i + 1, nums, arr, ans);
        arr.pop_back();
        solve(i + 1, nums, arr, ans);
        return;
    }

public:
    long long maxStrength(vector<int> &nums)
    {
        vector<int> arr;
        long long ans = -1e5;
        solve(0, nums, arr, ans);
        return ans;
    }
};
int main()
{

    return 0;
}