#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        int maxLen = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums1[i] >= nums1[i - 1])
            {
                dp1[i] = dp1[i - 1] + 1;
                maxLen = max(maxLen, dp1[i]);
            }

            if (nums2[i] >= nums2[i - 1])
            {
                dp2[i] = dp2[i - 1] + 1;
                maxLen = max(maxLen, dp2[i]);
            }

            if (nums1[i] >= nums2[i - 1])
            {
                dp1[i] = max(dp1[i], dp2[i - 1] + 1);
                maxLen = max(maxLen, dp1[i]);
            }

            if (nums2[i] >= nums1[i - 1])
            {
                dp2[i] = max(dp2[i], dp1[i - 1] + 1);
                maxLen = max(maxLen, dp2[i]);
            }
        }

        return maxLen;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    vector<int> nums2(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    Solution sol;
    cout << sol.maxNonDecreasingLength(nums1, nums2) << endl;

    return 0;
}