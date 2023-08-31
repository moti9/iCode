#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minimizeTopSpeed(int n, vector<int> &spells, long long trackLength)
    {
        long long low = 1, high = min(trackLength, (long long)1e9 + 1);
        long long ans = 1e15;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long speed = mid;
            long long dist = 0;
            for (int i = 1; i < n; i++)
            {
                long long midsum = (mid * (mid + 1)) / 2;

                long long k = (spells[i] - spells[i - 1]);

                if (mid <= k)
                    dist += midsum;
                else
                {
                    long long lmid = mid - k;
                    lmid = (lmid * (lmid + 1)) / 2;
                    dist += midsum - lmid;
                }
            }
            dist += (mid * (mid + 1)) / 2;
            if (dist >= trackLength)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> spells(n);
    for (int i = 0; i < n; i++)
    {
        cin >> spells[i];
    }

    long long trackLength;
    cin >> trackLength;

    Solution sol;
    cout << sol.minimizeTopSpeed(n, spells, trackLength) << endl;
    return 0;
}