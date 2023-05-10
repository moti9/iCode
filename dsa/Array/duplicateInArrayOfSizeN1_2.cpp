#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N+N)
// SC- O(N)
// Using frequency array of size N+1
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n);
        for (int i = 0; i < n; i++)
        {
            if (freq[nums[i]] != 0)
                return nums[i];
            freq[nums[i]] += 1;
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}