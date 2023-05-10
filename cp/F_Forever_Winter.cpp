#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, m;
    cin >> n >> m;
    // vector<int> adj[n + 1];
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // adj[u].push_back(v);
        cnt[u] += 1;
        cnt[v] += 1;
    }
    // vector<int> vis(n + 1);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[cnt[i]] += 1;
    vector<int> ans;
    for (auto m : mp)
        ans.push_back(m.second);
    sort(ans.begin(), ans.end());
    if (ans.size() != 3)
    {
        cout << ans[0] - 1 << " " << ans[1] / (ans[0] - 1) << "\n";
        return;
    }
    cout << ans[1] << " " << ans[2] / ans[1] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
