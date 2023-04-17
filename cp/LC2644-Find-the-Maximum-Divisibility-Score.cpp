#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int ans = 1e5, maxct = 0;
        for (int j = 0; j < divisors.size(); j++)
        {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] % divisors[j] == 0)
                {
                    cnt++;
                }
            }
            if (cnt > maxct)
            {
                ans = divisors[j];
                maxct = cnt;
            }
            else if (cnt == maxct)
            {
                ans = min(ans, divisors[j]);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), divs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> divs[i];
    }
    Solution sol;
    cout << sol.maxDivScore(nums, divs) << endl;

    return 0;
}