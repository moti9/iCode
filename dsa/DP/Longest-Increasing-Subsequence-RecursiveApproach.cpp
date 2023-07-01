#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findLenOfLIS(int ind, int prevInd, vector<int> &nums)
    {

        if (ind == nums.size())
        {
            return 0;
        }

        int len = findLenOfLIS(ind + 1, prevInd, nums);

        if (prevInd == -1 || nums[ind] > nums[prevInd])
        {
            len = max(len, 1 + findLenOfLIS(ind + 1, ind, nums));
        }
        return len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return findLenOfLIS(0, -1, nums);
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
    cout << sol.lengthOfLIS(nums) << endl;

    return 0;
}