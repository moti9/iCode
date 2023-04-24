#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int getPoints(int day, int last, vector<vector<int>> points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + getPoints(day - 1, i, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

// Memoization
int getPoints(int day, int last, vector<vector<int>> points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + getPoints(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

// Tabulation

int getPoints(vector<vector<int>> points, vector<vector<int>> &dp)
{
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    int n = points.size();
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (last != task)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n - 1][3];
}

// Space Optimization
int getPoints(vector<vector<int>> points)
{
    vector<int> dp(4, -1);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max({points[0][0], points[0][1], points[0][2]});

    int n = points.size();
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (last != task)
                {
                    temp[last] = max(temp[last], points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }

    // Recursive
    cout << getPoints(n - 1, 3, points) << endl;

    // Memoization
    // vector<vector<int>> dp(n, vector<int>(4, -1));
    // cout << getPoints(n - 1, 3, points, dp) << endl;

    // Tabulation
    // cout << getPoints(points, dp) << endl;

    // Space Optimization
    cout << getPoints(points) << endl;

    return 0;
}