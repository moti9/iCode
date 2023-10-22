#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long double findMinimumDistance(vector<int> &stations, int n, int k)
    {
        vector<int> hasMany(n - 1, 0);
        for (int gasSt = 1; gasSt <= k; gasSt++)
        {
            long double maxSection = -1;
            int maxInd = -1;
            for (int i = 0; i < n - 1; i++)
            {
                long double dist = stations[i + 1] - stations[i];
                long double section = dist / (long double)(hasMany[i] + 1);
                if (maxSection < section)
                {
                    maxSection = section;
                    maxInd = i;
                }
            }
            hasMany[maxInd]++;
        }
        long double result = 0;
        for (int i = 0; i < n - 1; i++)
        {
            long double dist = stations[i + 1] - stations[i];
            long double section = dist / (long double)(hasMany[i] + 1);
            result = max(result, section);
        }
        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stations[i];
    }

    int m;
    cin >> m;

    Solution sol;
    cout << sol.findMinimumDistance(stations, n, m) << endl;

    return 0;
}