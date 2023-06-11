#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*4*3)
// SC- O(4*N)

class Solution
{
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4));
        // dp[0][0] = max(points[0][1], points[0][2]);
        // dp[0][1] = max(points[0][0], points[0][2]);
        // dp[0][2] = max(points[0][0], points[0][1]);
        // dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

        for (int last = 0; last < 4; last++)
        {
            int maxPoint = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxPoint = max(maxPoint, points[0][task]);
                }
            }
            dp[0][last] = maxPoint;
        }
        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                int maxPoint = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int point = points[day][task] + dp[day - 1][task];
                        maxPoint = max(maxPoint, point);
                    }
                }
                dp[day][last] = maxPoint;
            }
        }
        return dp[n - 1][3];
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