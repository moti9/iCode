#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*4*3)
// SC- O(N*4+N)

class Solution
{
    int getPoints(int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            int maxPoint = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    maxPoint = max(maxPoint, points[ind][i]);
                }
            }
            return maxPoint;
        }
        if (dp[ind][last] != -1)
        {
            return dp[ind][last];
        }
        int maxPoint = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int point = points[ind][i] + getPoints(ind - 1, i, points, dp);
                maxPoint = max(maxPoint, point);
            }
        }
        return dp[ind][last] = maxPoint;
    }

public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return getPoints(n - 1, 3, points, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    Solution sol;
    cout << sol.ninjaTraining(n, points) << endl;

    return 0;
}