#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    if (n >= 0)
    {
        cout << n;
    }
    else
    {
        int temp = 0 - n;
        int last = temp % 10;
        int secLast = (temp % 100) / 10;
        if (last >= secLast)
        {
            temp /= 10;
            cout << 0 - temp;
        }
        else
        {
            temp /= 100;
            temp = temp * 10 + last;
            cout << 0 - temp;
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
