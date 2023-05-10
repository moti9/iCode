#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<vector<ll>> cans(1501);
vector<vector<int>> vis(1501);
vector<pair<int, int>> pos(2000008);

ll cntcans(ll row, ll col, vector<vector<int>> vis)
{
    if (row >= 0 && row < 1501 && col >= 0 && col < 1501 && col <= row)
    {
        if (vis[row][col])
            return 0;
        vis[row][col] = 1;
        ll left = cntcans(row - 1, col - 1, vis);
        ll right = cntcans(row - 1, col, vis);
        return cans[row][col] + left + right;
    }
    return 0;
}

void gencans()
{
    ll val = 1;
    for (ll row = 0; row < 1501; row++)
    {
        cans[row].resize(row + 1);
        vis[row].resize(row + 1);
        for (ll col = 0; col <= row; col++)
        {
            pos[val] = {row, col};
            cans[row][col] = val * val;
            val += 1;
        }
    }
}

void solvehere()
{
    ll n;
    cin >> n;
    auto p = pos[n];
    ll ans = cntcans(p.first, p.second, vis);
    cout << ans << "\n";
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
    gencans();
    while (ttt--)
    {
        solvehere();
    }

    return 0;
}
