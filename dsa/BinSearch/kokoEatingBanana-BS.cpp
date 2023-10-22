#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findTime(vector<int> &banana_piles, int n, int speed)
    {
        int time = 0;
        for (int i = 0; i < n; i++)
        {
            time += ceil((float)banana_piles[i] / (float)speed);
        }
        return time;
    }

public:
    int solve(vector<int> &banana_piles, int n, int hr)
    {
        int low = 1, high = *max_element(banana_piles.begin(), banana_piles.end());
        int result = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int req_time = findTime(banana_piles, n, mid);
            if (req_time <= hr)
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> banana_piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> banana_piles[i];
    }
    int hr;
    cin >> hr;

    Solution sol;
    cout << sol.solve(banana_piles, n, hr) << endl;

    return 0;
}