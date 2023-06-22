#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {
        int dist = 0;
        while (mainTank >= 5)
        {
            dist += 50;
            mainTank -= 5;
            if (additionalTank > 0)
            {
                additionalTank -= 1;
                mainTank += 1;
            }
        }
        if (mainTank > 0)
        {
            dist += (mainTank * 10);
        }
        return dist;
    }
};

int main()
{
    int mainTank, additionalTank;
    cin >> mainTank >> additionalTank;

    Solution sol;
    cout << sol.distanceTraveled(mainTank, additionalTank) << endl;

    return 0;
}