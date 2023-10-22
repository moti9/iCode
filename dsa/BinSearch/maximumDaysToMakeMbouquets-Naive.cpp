#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findNumberOfBouquets(vector<int> &bloom_day, int n, int k, int day)
    {
        int bouquets = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloom_day[i] <= day)
            {
                cnt += 1;
            }
            else
            {
                bouquets += (cnt / k);
                cnt = 0;
            }
        }
        bouquets += (cnt / k);
        return bouquets;
    }

public:
    int solve(vector<int> &bloom_day, int n, int m, int k)
    {
        int low = *min_element(bloom_day.begin(), bloom_day.end());
        int high = *max_element(bloom_day.begin(), bloom_day.end());
        if (m * k > n)
        {
            return -1;
        }
        for (int day = low; day <= high; day++)
        {
            int nob = findNumberOfBouquets(bloom_day, n, k, day);
            if (nob >= m)
            {
                return day;
            }
        }
        return high;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> bloom_days(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bloom_days[i];
    }
    int m, k;
    cin >> m >> k;

    Solution sol;
    cout << sol.solve(bloom_days, n, m, k) << endl;

    return 0;
}