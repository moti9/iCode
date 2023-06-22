#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Need to optimmize

class Solution
{
    int permutations(int st, int end, int n, vector<int> &nums)
    {
        if (st == end)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if ((nums[i] % nums[i + 1]) == 0 || (nums[i + 1] % nums[i]) == 0)
                {
                    continue;
                }
                return 0;
            }
            return 1;
        }
        int cnt = 0;
        for (int i = st; i <= end; i++)
        {
            swap(nums[st], nums[i]);
            cnt += permutations(st + 1, end, n, nums);
            swap(nums[st], nums[i]);
        }
        return cnt;
    }

public:
    int specialPerm(vector<int> &nums)
    {
        int n = nums.size();
        return permutations(0, n - 1, n, nums);
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
    cout << sol.specialPerm(nums) << endl;

    return 0;
}