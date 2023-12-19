#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    // vector<vector<int>> edges(n - 1, vector<int>(2));
    unordered_map<int, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        // cin >> edges[i][0] >> edges[i][1];
        int u, v;
        cin >> u >> v;
        mp[u]++;
        mp[v]++;
    }
    int cnt = 0;
    for (auto &m : mp)
    {
        if (m.second == 1)
        {
            cnt += 1;
        }
    }
    cout << (cnt + 1) / 2 << "\n";
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
