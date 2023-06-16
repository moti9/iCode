#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long long countWays(vector<int> &nums, vector<vector<long long>> &pt)
    {
        int n = nums.size();
        if (n < 3)
        {
            return 1;
        }
        vector<int> leftSubtree, rightSubtree;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[0])
            {
                leftSubtree.push_back(nums[i]);
            }
            else
            {
                rightSubtree.push_back(nums[i]);
            }
        }
        long long left = countWays(leftSubtree, pt) % mod;
        long long right = countWays(rightSubtree, pt) % mod;

        long long total = (((left * right) % mod) * pt[n - 1][leftSubtree.size()]) % mod;
        return total;
    }

public:
    int numOfWays(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<long long>> pascal_table(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            pascal_table[i] = vector<long long>(i + 1);
            pascal_table[i][0] = pascal_table[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                pascal_table[i][j] = (pascal_table[i - 1][j] + pascal_table[i - 1][j - 1]) % mod;
            }
        }
        long long totalways = (countWays(nums, pascal_table) - 1) % mod;
        return totalways;
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
    cout << sol.numOfWays(nums) << endl;

    return 0;
}