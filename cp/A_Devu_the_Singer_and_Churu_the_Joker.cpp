#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, d;
    cin >> n >> d;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        sum +=t;
    }
    int req = (n - 1) * 10 + sum;
    if (d < req)
    {
        cout << -1;
    }
    else
    {
        int joke = (d - req) / 5;
        cout << joke + (n - 1) * 2;
    }
    // cout << "\n";
    // cout << req << endl;
    // cout << sum << endl;
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
