#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(NlogN)+O(N*N)
// SC- O(2*N)
// Brute force- sort then merge
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][0];
            if (!ans.empty())
            {
                auto temp = ans.back();
                if (start <= temp[1])
                {
                    continue;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                if (intervals[j][0] <= end)
                {
                    end = max(end, intervals[j][1]);
                }
            }
            end = max(end, intervals[i][1]);
            ans.push_back({start, end});
        }
        return ans;
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