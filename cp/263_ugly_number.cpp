#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }

        while (n % 2 == 0)
        {
            n /= 2;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        while (n % 5 == 0)
        {
            n /= 5;
        }
        return n == 1;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Solution sol;

    cout << (sol.isUgly(n) ? "Yes" : "No") << endl;

    return 0;
}