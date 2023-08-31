#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int theMaximumAchievableX(int num, int t)
    {
        return num + 2 * t;
    }
};

int main()
{
    int n, t;
    cin >> n >> t;

    Solution sol;

    cout << sol.theMaximumAchievableX(n, t) << endl;

    return 0;
}