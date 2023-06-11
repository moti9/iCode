#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(3^N)
// SC- O(N)

class Solution
{
    int getPoints(int ind, int last, vector<vector<int>> &points)
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
        int maxPoint = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int point = points[ind][i] + getPoints(ind - 1, i, points);
                maxPoint = max(maxPoint, point);
            }
        }
        return maxPoint;
    }

public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        return getPoints(n - 1, 3, points);
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