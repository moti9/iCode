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
        priority_queue<pair<long double, int>> pq;
        for (int i = 0; i < n - 1; i++)
        {
            long double dist = stations[i + 1] - stations[i];
            pq.push({dist, i});
        }
        for (int gasSt = 1; gasSt <= k; gasSt++)
        {
            auto node = pq.top();
            pq.pop();
            int ind = node.second;
            hasMany[ind]++;
            long double diff = stations[ind + 1] - stations[ind];
            long double section = diff / (long double)(hasMany[ind] + 1);
            pq.push({section, ind});
        }
        return pq.top().first;
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