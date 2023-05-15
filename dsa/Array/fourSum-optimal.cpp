#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimal Approach: 2 Loop+ 2 Pointer
// TC- O(N*N*N)
// SC- O(M), M = no. of quadruplets

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> quad;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                long long sum = (long long)nums[i] + (long long)nums[j];
                //  2-Pointer
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long s = (long long)nums[k] + (long long)nums[l];
                    if (s == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        quad.push_back(temp);
                        k += 1;
                        l -= 1;
                        while (k < l && nums[k] == nums[k - 1])
                            k += 1;
                        while (k < l && nums[l] == nums[l + 1])
                            l -= 1;
                    }
                    else if (s > target)
                    {
                        l -= 1;
                    }
                    else
                    {
                        k += 1;
                    }
                }
            }
        }
        return quad;
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
    vector<vector<int>> ans = sol.fourSum(nums, target);

    for (auto arr : ans)
    {
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}