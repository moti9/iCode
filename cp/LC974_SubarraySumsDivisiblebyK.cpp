#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

//Naive Approach
/*
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum % k == 0)
            {
                ct++;
            }
        }
    }
    return ct;
}
*/

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ct = 0;
        int currSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];
            int m = (currSum % k + k) % k;
            if (mp[m] > 0)
            {
                ct += mp[m];
            }
            mp[m]++;
        }
        return ct;
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
    cout << sol.subarraysDivByK(nums, k) << endl;

    return 0;
}