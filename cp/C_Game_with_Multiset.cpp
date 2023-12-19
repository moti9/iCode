#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(multiset<int> &mst, int val)
{
    for (int subsetSum : mst)
    {
        int remaining = val;
        for (int bit = 29; bit >= 0; bit--)
        {
            int currentPower = 1 << bit;
            int count = min(remaining / currentPower, 1);
            remaining -= count * currentPower;
        }

        if (remaining == 0 || mst.count(remaining) > 0)
        {
            return true;
        }
    }
    return false;
}

void solvehere()
{
    multiset<int> mst;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t, v;
        cin >> t >> v;
        if (t == 1)
        {
            mst.insert(1 << v);
        }
        else
        {
            if (check(mst, v))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
