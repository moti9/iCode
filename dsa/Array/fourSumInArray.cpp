#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Naive Approach (Brute-force):
// TC- O(N*N*N*N)
// SC- O(4*M)--M=no. of quadruplets

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                        if (sum == target)
                        {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> quad(st.begin(), st.end());
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