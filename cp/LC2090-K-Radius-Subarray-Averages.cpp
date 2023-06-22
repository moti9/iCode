#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        int len = 2 * k + 1;
        if (n < len)
        {
            return ans;
        }
        long long sumSubArr = 0;
        for (int i = 0; i < len; i++)
        {
            sumSubArr += (long long)nums[i];
        }
        ans[k] = (int)(sumSubArr / len);
        for (int i = len; i < n; i++)
        {
            sumSubArr = sumSubArr + (long long)nums[i] - (long long)nums[i - len];
            ans[i - k] = (int)(sumSubArr / len);
        }
        return ans;
    }
};

/*
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (n <= 2 * k)
        {
            return ans;
        }
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = (prefix[i - 1] +(long long) nums[i]);
        }
        long long len = 2 * (long long)k + 1;
        for (int i = k; i < n - k; i++)
        {
            long long sum = prefix[i + k];
            if (i - k - 1 >= 0)
            {
                sum -= prefix[i - k - 1];
            }
            ans[i] = (int)(sum / len);
        }
        return ans;
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

    int k;
    cin >> k;

    Solution sol;
    vector<int> ans = sol.getAverages(nums, k);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}