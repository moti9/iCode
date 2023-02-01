#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    // int solve(int ind, int young, int old, int &maxi, vector<int> &scores, vector<int> &ages)
    // {
    //     if (ind >= scores.size())
    //     {
    //         return 0;
    //     }
    //     int take = 0, nottake = 0;
    //     nottake = solve(ind + 1, young, old, maxi, scores, ages);

    //     int yg = young;
    //     int od = old;
    //     if (ages[ind] <= ages[young] && scores[ind] >= scores[young])
    //     {
    //         yg = ind;
    //     }
    //     if (ages[ind] >= ages[old] && scores[ind] >= scores[old])
    //     {
    //         od = ind;
    //     }
    //     if (scores[yg] <= scores[od])
    //     {
    //         take = scores[ind] + solve(ind + 1, yg, od, maxi, scores, ages);
    //     }

    //     int temp = max(take, nottake);
    //     maxi = max(maxi, temp);
    //     return temp;
    // }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        // int index = 0, maxi = 0;
        // solve(0, index, index, maxi, scores, ages);
        // return maxi;
        int n = scores.size();
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++)
        {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());

        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = players[i].second;
            for (int j = 0; j < i; j++)
            {
                if (players[j].second <= players[i].second)
                {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> scores(n), ages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ages[i];
    }

    Solution sol;
    cout << sol.bestTeamScore(scores, ages) << endl;

    return 0;
}