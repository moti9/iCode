#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, cntZero = 0, winSize = 0;
        for (int i = 0; i < n; i++)
        {
            cntZero += (nums[i] == 0) ? 1 : 0;

            while (cntZero > 1)
            {
                cntZero -= (nums[start] == 0) ? 1 : 0;
                start += 1;
            }
            winSize = max(winSize, i - start);
        }
        return winSize;
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
    cout << sol.longestSubarray(nums) << endl;

    return 0;
}