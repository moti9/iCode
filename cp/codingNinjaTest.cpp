#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll solve(int ind, int score, vector<int> &a, vector<int> &b, vector<vector<ll>> &dp, bool freeGame)
{
    if (ind == 0)
    {
        if (freeGame == false)
        {
            return 0;
        }
        if (score == a[0])
        {
            return b[0];
        }
        return 1e15;
    }
    if (dp[ind][score] != -1)
    {
        return dp[ind][score];
    }

    ll notTake = solve(ind - 1, score, a, b, dp, freeGame);
    ll take = 1e15;
    if (a[ind] <= score)
    {
        ll free = 1e15, notFree = 1e15;
        if (freeGame == true)
        {
            notFree = (ll)b[ind] + solve(ind - 1, score - a[ind], a, b, dp, freeGame);
        }
        else
        {
            free = solve(ind - 1, score - a[ind], a, b, dp, true);
        }
        take = min(free, notFree);
    }

    return dp[ind][score] = min(take, notTake);
}

int scoreAndCost(int n, vector<int> &a, vector<int> &b, int x)
{
    ll totalScore = 0;
    for (auto sc : a)
    {
        totalScore += (ll)sc;
    }
    if (totalScore < x)
    {
        return -1;
    }
    ll minCost = 1e15;
    for (ll nx = x; nx <= totalScore; nx++)
    {
        vector<vector<ll>> dp(n, vector<ll>(nx + 1, -1));
        ll cost = solve(n - 1, nx, a, b, dp, false);
        minCost = min(minCost, cost);
    }
    minCost = (minCost >= 1e15) ? -1 : minCost;
    return minCost;
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    int X;
    cin >> X;

    ll ans = scoreAndCost(n, A, B, X);
    cout << ans << endl;

    return 0;
}
