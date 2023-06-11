#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(3*N)
// SC- O(4*N)

class Solution
{
    long long maxCanRob(vector<int> valueInHouse)
    {
        int n = valueInHouse.size();

        vector<long long> dp(n);
        dp[0] = valueInHouse[0];
        for (int i = 1; i < n; i++)
        {
            long long take = (long long)valueInHouse[i];
            if (i > 1)
            {
                take += dp[i - 2];
            }
            long long notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }

public:
    long long int houseRobber(vector<int> &valueInHouse)
    {
        int n = valueInHouse.size();
        if (n == 1)
        {
            return valueInHouse[0];
        }
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                temp1.push_back(valueInHouse[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(valueInHouse[i]);
            }
        }
        long long left = maxCanRob(temp1);
        long long right = maxCanRob(temp2);
        return max(left, right);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> valueInHouse(n);
    for (int i = 0; i < n; i++)
    {
        cin >> valueInHouse[i];
    }

    Solution sol;
    cout << sol.houseRobber(valueInHouse) << endl;

    return 0;
}