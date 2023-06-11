#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Space Optimization
// TC- O(N)
// SC- O(1)

class Solution
{
public:
    int findNthFibonacciNumber(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int prev2 = 0;
        int prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.findNthFibonacciNumber(n) << endl;

    return 0;
}