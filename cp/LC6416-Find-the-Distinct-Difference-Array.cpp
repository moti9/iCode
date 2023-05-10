#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st, end;
        vector<int> suffix(n), prefix(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (end.empty())
                suffix[i] = 0;
            else
                suffix[i] = end.size();
            end.insert(nums[i]);
        }
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
            prefix[i] = st.size();
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix[i] - suffix[i];
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
    vector<int> ans = sol.distinctDifferenceArray(nums);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}