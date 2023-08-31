#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLen = n + 1;
        int left = 0, right = 0, sum = 0;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left += 1;
            }
        }
        if (minLen > n)
        {
            return 0;
        }
        return minLen;
    }
};

/*
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLen = n + 1;
        for (int i = 0; i < n; i++)
        {
            int len = 0;
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                len += 1;
                sum += nums[j];

                if (sum >= target)
                {
                    minLen = min(minLen, len);
                    break;
                }
            }
        }
        if (minLen > n)
        {
            return 0;
        }
        return minLen;
    }
};

*/

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution sol;
    cout << sol.minSubArrayLen(target, nums) << endl;

    return 0;
}