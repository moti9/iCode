#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool isValid(int i, int k, vector<int> &nums)
    {
        int n = nums.size();
        if (i + k > n)
        {
            return -1;
        }
        int mini = nums[i];
        for (int j = i; j < i + k; j++)
        {
            if (nums[j] == 0)
            {
                return -1;
            }
            mini = min(mini, nums[j]);
        }
        return mini;
    }

    bool check(int i, int k, long long sum, vector<int> &nums)
    {
        if (i == nums.size())
        {
            return sum == 0;
        }
        if (check(i + 1, k, sum, nums))
        {
            return true;
        }
        int mini = isValid(i, k, nums);
        if (mini != -1)
        {
            long long temp = (long long)mini * (long long)k;
            sum -= temp;
            if (check(i + 1, k, sum, nums))
            {
                return true;
            }
            sum += temp;
        }
        return false;
    }

public:
    bool checkArray(vector<int> &nums, int k)
    {
        long long sum = 0;
        for (auto &num : nums)
            sum += num;
        return check(0, k, sum, nums);
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
    cout << sol.checkArray(nums, k) << endl;

    return 0;
}