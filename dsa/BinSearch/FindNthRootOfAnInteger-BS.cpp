#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    // ll binPow(ll x, ll n)
    // {
    //     ll result = 1;
    //     while (n > 0)
    //     {
    //         if (n & 1)
    //             result *= x;
    //         x = x * x;
    //         n >>= 1;
    //     }
    //     return result;
    // }

    int validate(ll x, ll n, ll m)
    {
        ll result = 1;
        for (int i = 1; i <= n; i++)
        {
            result = result * x;
            if (result > m)
                return 2;
        }
        return result == m;
    }

public:
    int solve(int number, int n)
    {
        ll low = 1, high = number;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            int minN = validate(mid, n, number);
            if (minN == 1)
            {
                return mid;
            }
            else if (minN == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int number;
    int n;
    cin >> number >> n;

    Solution sol;
    cout << sol.solve(number, n) << endl;

    return 0;
}