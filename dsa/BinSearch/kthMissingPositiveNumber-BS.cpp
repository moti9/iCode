#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int findKthMissingNumber(vector<int> &nums, int n, int k)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int misssing = nums[mid] - mid - 1;
            if (misssing >= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return k + low;
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