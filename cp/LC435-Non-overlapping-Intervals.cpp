#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool static comp(const vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), comp);

        int cnt = 0;
        int recentEnd = -1e6;

        int n = intervals.size();

        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start >= recentEnd)
            {
                recentEnd = end;
            }
            else
            {
                cnt += 1;
            }
        }
        return cnt;
    };
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
    }

    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals) << endl;

    return 0;
}