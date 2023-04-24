#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long long check(vector<int> &piles, int &k)
    {
        long long h = 0;
        for (auto t : piles)
        {
            h += (k / t);
        }
        return h;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = 1e9;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (check(piles, mid) <= h)
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
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }
    int h;
    cin >> h;

    Solution sol;
    cout << sol.minEatingSpeed(piles, h) << endl;

    return 0;
}