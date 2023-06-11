#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(1)

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev2 = 1, prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
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