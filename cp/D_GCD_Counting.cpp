#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll calculateDist(int node, int par, vector<int> &a, vector<ll> &dp, vector<int> adj[])
{
    // Write logic
}

void solve(int n, vector<int> &a, vector<int> adj[])
{
    vector<ll> dp(n + 1);
    ll ans = 0;
    calculateDist(0, -1, a, dp, adj);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> adj[n + 1];
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        solve(n, a, adj);
    }
    return 0;
}