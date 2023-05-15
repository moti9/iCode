#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Brute Force
// TC- O(N*N*N)
// SC- O(1)

class Solution
{
    bool check(int n, vector<int> &nums, int num)
    {
        int i = 0;
        while (i < n)
        {
            if (nums[i] == num)
                return true;
            i += 1;
        }
        return false;
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        int maxlc = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            int num = nums[i] + 1;
            while (check(n, nums, num))
            {
                num += 1;
                cnt += 1;
            }
            maxlc = max(maxlc, cnt);
        }
        return maxlc;
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

    cout << sol.longestConsecutive(nums) << endl;

    return 0;
}