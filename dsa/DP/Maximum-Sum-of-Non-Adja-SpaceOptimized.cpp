#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(1)

class Solution
{

public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += prev2;
            }
            int notTake = 0 + prev;
            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }
        return prev;
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
    cout << sol.maximumNonAdjacentSum(nums) << endl;

    return 0;
}