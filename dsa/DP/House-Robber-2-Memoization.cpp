#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(3*N)
// SC- O(4*N+N)

class Solution
{
    long long maxCanRob(int ind, vector<int> &valueInHouse, vector<long long> &dp)
    {
        if (ind < 0)
        {
            return 0;
        }
        if (ind == 0)
        {
            return valueInHouse[0];
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        long long left = (long long)valueInHouse[ind] + maxCanRob(ind - 2, valueInHouse, dp);
        long long right = maxCanRob(ind - 1, valueInHouse, dp);
        return dp[ind] = max(left, right);
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
        vector<long long> dp1(n - 1, -1);
        vector<long long> dp2(n - 1, -1);
        long long left = maxCanRob(n - 2, temp1, dp1);
        long long right = maxCanRob(n - 2, temp2, dp2);
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