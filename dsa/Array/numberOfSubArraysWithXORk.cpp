#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Brute force- Generate all subarrays with xor and count for xor==k
// TC- O(N*N)
// SC- O(1)

class Solution
{
public:
    int countSubarraysWithXORk(vector<int> &nums, int k)
    {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int xorr = 0;
            for (int j = i; j < n; j++)
            {
                xorr ^= nums[j];
                if (xorr == k)
                    cnt += 1;
            }
        }
        return cnt;
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
    cout << sol.countSubarraysWithXORk(nums, k) << endl;

    return 0;
}