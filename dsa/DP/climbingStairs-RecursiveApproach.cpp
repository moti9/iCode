#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int findSteps(int ind)
    {
        if (ind == 0 || ind == 1)
        {
            return 1;
        }
        return findSteps(ind - 1) + findSteps(ind - 2);
    }

public:
    int climbStairs(int n)
    {
        return findSteps(n);
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.climbStairs(n) << endl;

    return 0;
}