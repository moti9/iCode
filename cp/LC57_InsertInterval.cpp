#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int i = 0;
    while (i < intervals.size())
    {
        if (intervals[i][1] < newInterval[0])
        {
            i++;
        }
        else if (intervals[i][0] > newInterval[1])
        {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        }
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            intervals.erase(intervals.begin() + i);
        }
    }
    intervals.push_back(newInterval);
    return intervals;
}
*/

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;
    for (; i < n; i++)
    {
        if (intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
        }
        else if (intervals[i][0] > newInterval[1])
        {
            break;
        }
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    ans.push_back(newInterval);
    ans.insert(ans.end(), intervals.begin() + i, intervals.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> interval;
    for (int i = 0; i < n; i++)
    {
        int st, end;
        cin >> st >> end;
        interval.push_back({st, end});
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> ans = insert(interval, newInterval);

    for (auto arr : ans)
    {
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}