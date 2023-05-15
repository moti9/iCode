#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Better Approach (Using 1 loop and 2 pointer):
// TC- O(N*N), where N = size of the array
// SC- O(3*M), M =  no. of the triplets

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            long sum = (long long)nums[i];
            //  2-Pointer
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                long long s = (long long)nums[j] + (long long)nums[k];
                if (s == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    triplets.push_back(temp);
                    j += 1;
                    k -= 1;
                    while (j < k && nums[j] == nums[j - 1])
                        j += 1;
                    while (j < k && nums[k] == nums[k + 1])
                        k -= 1;
                }
                else if (s > target)
                {
                    k -= 1;
                }
                else
                {
                    j += 1;
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