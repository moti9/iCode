#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimal approach- Using HashSet
// TC- O(N)+O(N)
// SC- O(N)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto num : nums)
            st.insert(num);
        int maxlc = 0;
        for (auto num : nums)
        {
            if (st.count(num - 1))
                continue;
            else
            {
                int currnum = num;
                int cntlc = 1;
                while (st.count(currnum + 1))
                {
                    currnum += 1;
                    cntlc += 1;
                }
                maxlc = max(maxlc, cntlc);
            }
        }
        return maxlc;
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

    cout << sol.longestConsecutive(nums) << endl;

    return 0;
}