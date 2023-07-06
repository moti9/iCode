#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[prev] < nums[ind])
                {
                    left[ind] = max(left[ind], 1 + left[prev]);
                }
            }
        }
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = n - 1; prev > ind; prev--)
            {
                if (nums[prev] < nums[ind])
                {
                    right[ind] = max(right[ind], 1 + right[prev]);
                }
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            maxLen = max(maxLen, left[i] + right[i] - 1);
        }
        return maxLen;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans << "\n";
    }
    return 0;
}