#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Better Approach- Using Sorting
// TC- O(NlogN)+O(N)
// SC- O(1)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxlc = 0;
        int n = nums.size();
        int currcnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    currcnt += 1;
                }
                else
                {
                    maxlc = max(maxlc, currcnt);
                    currcnt = 1;
                }
            }
        }
        maxlc = max(maxlc, currcnt);
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