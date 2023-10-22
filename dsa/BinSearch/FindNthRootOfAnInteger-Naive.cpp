#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    ll binPow(ll x, ll n)
    {
        ll result = 1;
        while (n > 0)
        {
            if (n & 1)
                result *= x;
            x = x * x;
            n >>= 1;
        }
        return result;
    }

public:
    int solve(int number, int n)
    {
        for (int i = 1; i <= number; i++)
        {
            ll powVal = binPow(i, n);
            if (powVal == number)
            {
                return i;
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