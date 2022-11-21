#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(ll n)
{
    if (n < 15)
    {
        return 0;
    }
    ll a[6] = {15, 16, 17, 18, 19, 20};
    // ll b[3] = {13, 14, 15};
    for (int i = 0; i < 6; i++)
    {
        ll temp = n - a[i];
        if (temp % 14 == 0)
        {
            return 1;
        }
        // for (int j = 0; j < 3; j++)
        // {

        //     if (temp % b[j] == 0)
        //     {
        //         return 1;
        //     }
        // }
    }
    return 0;
}

void solvehere()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (check(x))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
