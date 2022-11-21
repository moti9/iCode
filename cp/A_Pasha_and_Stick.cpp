#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << 0;
        return;
    }
    // int temp = n / 2;
    // int ct = 0;
    // for (int i = 1; i <= temp / 2; i++)
    // {
    //     int a = temp - i;
    //     int b = temp - a;
    //     if (a != b)
    //     {
    //         ct++;
    //     }
    // }
    // cout << ct;
    if (n % 4)
    {
        cout << n / 4;
    }
    else
    {
        cout << (n / 4) - 1;
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
