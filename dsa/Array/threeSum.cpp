#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Naive Approach (Brute-force):
// TC- O(N*N*N)
// SC- O(3*M)--M=no. of triplets

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> triplets;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        triplets.push_back(temp);
                    }
                }
            }
        }
        return triplets;
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
    int target;
    cin >> target;

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums, target);

    for (auto arr : ans)
    {
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}