#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            int left = nums[i];
            while (i + 1 < n && nums[i] + 1 == nums[i + 1])
            {
                i += 1;
            }

            if (left != nums[i])
            {
                string st = to_string(left) + "->" + to_string(nums[i]);
                ans.push_back(st);
            }
            else
            {
                string st = to_string(left);
                ans.push_back(st);
            }
        }
        return ans;
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
    vector<string> ans = sol.summaryRanges(nums);

    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}