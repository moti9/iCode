#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool cmp(vector<int> a, vector<int> b)
{
    return (a[1] < b[1]);
}

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), cmp);
    int count = 1, end = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if (end < points[i][0])
        {
            end = points[i][1];
            count += 1;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> point;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        point.push_back({x1, x2});
    }

    cout << findMinArrowShots(point);

    return 0;
}