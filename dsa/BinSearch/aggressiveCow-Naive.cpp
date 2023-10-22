#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool canPlaceAll(vector<int> &stalls, int n, int cows, int gap)
    {
        int cnt = 1;
        int start = 0;
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - stalls[start] >= gap)
            {
                cnt += 1;
                start = i;
            }
            if (cnt >= cows)
                return true;
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &stalls, int n, int cows)
    {
        sort(stalls.begin(), stalls.end());
        int limit = stalls[n - 1] - stalls[0];
        for (int gap = 1; gap <= limit; gap++)
        {
            if (canPlaceAll(stalls, n, cows, gap))
            {
                continue;
            }
            else
            {
                return gap - 1;
            }
        }
        return limit;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    int cows;
    cin >> cows;

    Solution sol;
    cout << sol.aggressiveCows(stalls, n, cows) << endl;

    return 0;
}