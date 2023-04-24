#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b)
    {
        return true;
    }
    return false;
}

void solvehere()
{
    string p, h;
    cin >> p >> h;
    int n = p.size();
    int m = h.size();

    for (int i = 0; i <= m - n; i++)
    {
        if (check(h.substr(i, n), p))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
