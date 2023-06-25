#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1));

        for (int i = 0; i <= fuel; i++)
        {
            dp[finish][i] = 1;
        }

        for (int j = 0; j <= fuel; j++)
        {
            for (int ind = start; ind <= finish; ind++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (ind != ind && abs(locations[start] - locations[i]) <= fuel)
                    {
                        dp[ind][j] = (dp[ind][j] + dp[i][fuel - abs(locations[start] - locations[i])]) % mod;
                    }
                }
            }
        }
        return dp[start][fuel];
    }
};

/*
class Solution
{
    int countRoutes(int start, int fuel, int finish, vector<int> &locations, vector<vector<int>> &dp)
    {
        if (fuel < 0)
        {
            return 0;
        }
        if (dp[start][fuel] != -1)
        {
            return dp[start][fuel];
        }
        int ans = (start == finish) ? 1 : 0;
        for (int i = 0; i < locations.size(); i++)
        {
            if (start != i)
            {
                ans = (ans + countRoutes(i, fuel - abs(locations[start] - locations[i]), finish, locations, dp)) % mod;
            }
        }
        return dp[start][fuel] = ans;
    }

public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        return countRoutes(start, fuel, finish, locations, dp);
    }
};

*/

int main()
{
    int n;
    cin >> n;
    vector<int> locations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> locations[i];
    }

    int start, finish, fuel;
    cin >> start;
    cin >> finish;
    cin >> fuel;

    Solution sol;
    cout << sol.countRoutes(locations, start, finish, fuel) << endl;

    return 0;
}