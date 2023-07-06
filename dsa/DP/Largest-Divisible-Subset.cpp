#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1), hash(n);

        int maxLen = 0, lastInd = 0;
        for (int ind = 0; ind < n; ind++)
        {
            hash[ind] = ind;
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if (dp[ind] > maxLen)
            {
                maxLen = dp[ind];
                lastInd = ind;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastInd]);

        while (hash[lastInd] != lastInd)
        {
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }
        return temp;
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
    vector<int> subset = sol.largestDivisibleSubset(nums);

    for (auto &s : subset)
        cout << s << " ";
    cout << endl;

    return 0;
}