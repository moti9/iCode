#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int findKthMissingNumber(vector<int> &nums, int n, int k)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= k)
                k += 1;
        }
        return k;
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

    int k;
    cin >> k;

    Solution sol;
    cout << sol.findKthMissingNumber(nums, n, k) << endl;

    return 0;
}