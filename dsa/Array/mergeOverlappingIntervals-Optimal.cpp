#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(NlogN)+O(N)
// SC- O(2*N)
// Optimal- sort and merge
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++)
        {
            if (merged.empty() || merged.back()[1] < intervals[i][0])
            {
                merged.push_back(intervals[i]);
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }
        return merged;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    Solution sol;
    vector<vector<int>> ans = sol.merge(intervals);
    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
    return 0;
}