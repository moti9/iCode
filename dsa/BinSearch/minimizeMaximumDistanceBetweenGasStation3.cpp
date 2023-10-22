#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int numberOfGasStationRequired(vector<int> &stations, int n, long double dist)
    {
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            int inBetween = (int)((stations[i] - stations[i - 1]) / dist);
            if ((stations[i] - stations[i - 1]) / dist == inBetween + dist)
            {
                inBetween--;
            }
            cnt += inBetween;
        }
        return cnt;
    }

public:
    long double findMinimumDistance(vector<int> &stations, int n, int k)
    {
        long double low = 0;
        long double high = 0;
        for (int i = 0; i < n - 1; i++)
        {
            high = max(high, (long double)(stations[i + 1] - stations[i]));
        }

        long double diff = 1e-6;
        while (high - low > diff)
        {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationRequired(stations, n, mid);
            if (cnt > k)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        return high;
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