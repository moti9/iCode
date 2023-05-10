#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using XOR
// TC- O(N)
// SC- O(1)

class Solution
{
public:
    vector<int> findRepeatingMissingNum(vector<int> &nums)
    {
        int xor1 = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            xor1 = xor1 ^ nums[i];
        }
        for (int i = 1; i <= n; i++)
        {
            xor1 = xor1 ^ i;
        }
        int numSetbit = xor1 & ~(xor1 - 1);
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & numSetbit)
            {
                x = x ^ nums[i];
            }
            else
            {
                y = y ^ nums[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i & numSetbit)
            {
                x = x ^ i;
            }
            else
            {
                y = y ^ i;
            }
        }
        int cntx = 0;
        for (int i = 0; i < n; i++)
        {
            if (x == nums[i])
                cntx += 1;
        }
        if (cntx != 0)
            x = -1;
        return {x, y};
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
    vector<int> ans = sol.findRepeatingMissingNum(nums);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}