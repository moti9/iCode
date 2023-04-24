#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long long countTrips(vector<int> &time, long long tt)
    {
        long long ctt = 0;
        for (auto t : time)
        {
            ctt += (tt / (long long)t);
        }
        return ctt;
    }

public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long low = 1, high = 1e14, ans = 0;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (countTrips(time, mid) >= totalTrips)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    int trips;
    cin >> trips;

    Solution sol;
    cout << sol.minimumTime(time, trips) << endl;

    return 0;
}