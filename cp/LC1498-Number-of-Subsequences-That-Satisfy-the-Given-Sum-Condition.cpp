#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define mod 1000000007

// TC- O(NlogN)
// SC- O(N)
class Solution
{
    int mod = 1e9 + 7;
    vector<int> getpowlist(int &n)
    {
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++)
        {
            power[i] = (power[i - 1] * 2) % mod;
        }
        return power;
    }

public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        int left = 0, right = n - 1;
        vector<int> power = getpowlist(n);
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                ans = ans + power[right - left];
                ans %= mod;
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
        return ans;
    }
};

// TC- O(NlogN)
// SC- O(N)

/*
class Solution
{
    int mod = 1e9 + 7;
    int binsearch(vector<int> &nums, int &tr)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= tr)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
    // int binpow(int a, int b) {
    // int res = 1;
    // while (b > 0) {
    //     if (b & 1)
    //         res = (res * a)%mod;
    //     a = (a * a)%mod;
    //     res%=mod;
    //     b >>= 1;
    // }
    // return res;
    // }
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int power[n];
        power[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            power[i] = (power[i - 1] * 2) % mod;
        }
        for (int left = 0; left < nums.size(); left++)
        {
            int temp = target - nums[left];
            int right = binsearch(nums, temp) - 1;
            if (left <= right)
            {
                // ans=ans+binpow(2,right-left);
                ans = ans + power[right - left];
                ans %= mod;
            }
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
    int target;
    cin >> target;
    Solution sol;
    cout << sol.numSubseq(nums, target) << endl;

    return 0;
}