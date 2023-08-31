#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int reverse(int x)
    {
        bool neg = false;
        if (x < 0)
        {
            neg = true;
            x = 0 - x;
        }
        long revNum = 0;
        while (x > 0)
        {
            if (revNum >= INT_MAX || revNum <= INT_MIN)
            {
                return 0;
            }
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }
        if (neg)
        {
            revNum = 0 - revNum;
        }
        return (int)revNum;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.reverse(n) << endl;

    return 0;
}