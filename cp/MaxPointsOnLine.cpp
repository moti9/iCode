#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int maxPoint = 0;
    int countMax, vertical;
    unordered_map<float, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        countMax = vertical = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (points[i][0] == points[j][0])
            {
                vertical++;
            }
            else
            {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];

                int g = __gcd(x, y);
                x /= g;
                y /= g;
                float slope = (float)y / (float)x;
                mp[slope]++;
                countMax = max(countMax, mp[slope]);
            }
            countMax = max(countMax, vertical);
        }
        maxPoint = max(maxPoint, countMax);
        mp.clear();
    }
    return maxPoint + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
    cout << maxPoints(points) << endl;

    return 0;
}