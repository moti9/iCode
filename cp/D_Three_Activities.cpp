#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a, b, c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back({x, i + 1});
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        c.push_back({x, i + 1});
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    ll sum = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second)
                {
                    sum = max(sum, (ll)a[i].first + (ll)b[j].first + (ll)c[k].first);
                }
            }
        }
    }
    cout << sum << "\n";
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
