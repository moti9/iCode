#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Binary Exponentiation
// TC- O(logN)
// SC- O(1)

class Solution
{
    double power(double x, int n)
    {
        double ans = 1.0;
        bool isneg = false;
        if (n < 0)
        {
            n = abs(n);
            isneg = true;
        }
        while (n > 0)
        {
            if (n & 1)
            {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        if (isneg)
        {
            ans = (double)(1.0 / ans);
        }
        return ans;
    }

public:
    double myPow(double x, int n)
    {
        return power(x, n);
    }
};

// Brute force approach
// TC- O(N)
// SC- O(1)
/*
class Solution
{
public:
    double myPow(double x, int n)
    {
        bool isneg = false;
        if (n < 0)
        {
            isneg = true;
            n = abs(n);
        }
        double ans = 1.0;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * x;
        }
        if (isneg)
        {
            ans = 1.0 / ans;
        }
        return ans;
    }
};
*/

int main()
{
    double x;
    int n;
    cin >> x >> n;

    Solution sol;
    cout << sol.myPow(x, n) << endl;
    return 0;
}