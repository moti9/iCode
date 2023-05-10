#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    vector<int> liars(n);
    for (int i = 0; i < n; i++)
    {
        cin >> liars[i];
    }
    for (int cntliars = 0; cntliars <= n; cntliars++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cntliars < liars[i])
            {
                cnt += 1;
            }
        }
        if (cnt == cntliars)
        {
            cout << cnt << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
