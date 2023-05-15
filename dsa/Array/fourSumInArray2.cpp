#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Better Approach (Using 3 loops and set data structure):
// TC- O(N*N*N*log(M)), where N = size of the array, M = no. of elements in the set.
// SC- O(4*M)+O(N), M =  no. of the quadruplets
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                unordered_set<long long> hasNum;
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    long long fourth = (long long)target - sum;
                    if (hasNum.find(fourth) != hasNum.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    hasNum.insert(nums[k]);
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