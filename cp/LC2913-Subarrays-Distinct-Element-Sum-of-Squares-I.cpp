#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> st;
            for (int j = i; j < nums.size(); j++)
            {
                st.insert(nums[j]);
                int cnt = st.size();
                result += (cnt * cnt);
            }
        }
        return result;
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
    cout << sol.sumCounts(nums) << endl;

    return 0;
}