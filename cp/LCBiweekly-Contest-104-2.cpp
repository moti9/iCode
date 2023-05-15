#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        for (int i = 0; i < n; i++)
        {
            sort(nums[i].begin(), nums[i].end());
        }
        int score = 0;
        while (true)
        {
            int maxi = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                int temp = nums[i].back();
                nums[i].pop_back();
                maxi = max(maxi, temp);
            }
            score += maxi;
            if (nums.size() == 0 || nums[0].size() == 0)
            {
                break;
            }
        }
        return score;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    Solution sol;
    cout << sol.matrixSum(nums) << endl;

    return 0;
}