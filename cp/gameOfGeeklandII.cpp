#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minTime(int n, std::vector<int> &health, std::vector<int> &power)
    {
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        int maxPower = 0;

        for (int i = 0; i < n - 1; i++)
        {
            maxPower = std::max(maxPower, power[i]);
            dp[i][1] = (health[i + 1] + maxPower - 1) / maxPower;

            for (int j = 2; j <= i + 1; j++)
            {
                dp[i][j] = dp[i - 1][j - 1];
                int currTime = (health[i + 1] + maxPower - 1) / maxPower;

                for (int k = i; k >= j - 1; k--)
                {
                    currTime = std::max(currTime, (health[k] + maxPower - 1) / maxPower);
                    dp[i][j] = std::min(dp[i][j], dp[k - 1][j - 1] + currTime);
                }
            }
        }

        int minTime = dp[n - 2][n - 1];
        return minTime;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> health(n), power(n);
    for (int i = 0; i < n; i++)
    {
        cin >> health[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> power[i];
    }

    Solution sol;
    cout << sol.minTime(n, health, power) << endl;

    return 0;
}