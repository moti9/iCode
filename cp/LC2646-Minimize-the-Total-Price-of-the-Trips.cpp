#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool countPath(int node, int dest, int pr, vector<int> adj[], vector<int> &cnt)
    {
        if (node == dest)
        {
            return true;
        }
        for (auto ad : adj[node])
        {
            if (ad != pr)
            {
                if (countPath(ad, dest, node, adj, cnt))
                {
                    cnt[ad]++;
                    return true;
                }
            }
        }
        return false;
    }

    int solve(int node, int pr, int divpr, vector<int> adj[], vector<int> &price, vector<vector<int>> &dp, vector<int> &cnt)
    {
        if (dp[node][divpr] != -1)
        {
            return dp[node][divpr];
        }
        int childs = 0;
        for (auto ad : adj[node])
            if (ad != pr)
                childs++;
        if (childs == 0)
        {
            if (divpr)
                return dp[node][divpr] = cnt[node] * price[node];
            return dp[node][divpr] = cnt[node] * (price[node] / 2);
        }
        if (divpr)
        {
            int ans = 0;
            for (auto ad : adj[node])
            {
                if (ad != pr)
                {
                    ans += solve(ad, node, 0, adj, price, dp, cnt);
                }
            }
            ans += cnt[node] * price[node];
            return dp[node][divpr] = ans;
        }
        int ans1 = 0, ans2 = 0;
        for (auto ad : adj[node])
        {
            if (ad != pr)
            {
                ans1 += solve(ad, node, 0, adj, price, dp, cnt);
                ans2 += solve(ad, node, 1, adj, price, dp, cnt);
            }
        }
        ans1 += cnt[node] * price[node];
        ans2 += cnt[node] * (price[node] / 2);
        return dp[node][divpr] = min(ans1, ans2);
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        vector<int> adj[n];
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> cnt(n, 0);
        for (auto tr : trips)
        {
            cnt[tr[0]]++;
            countPath(tr[0], tr[1], -1, adj, cnt);
        }
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, -1, 0, adj, price, dp, cnt);
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector<vector<int>> trips(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> trips[i][0] >> trips[i][1];
    }
    Solution sol;
    cout << sol.minimumTotalPrice(n, edges, price, trips) << endl;

    return 0;
}