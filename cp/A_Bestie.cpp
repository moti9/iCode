#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    bool one = false;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            one = true;
        }
    }
    if (one)
    {
        cout << 0 << "\n";
        return;
    }
    int gcd = arr[0];
    for (int i = 1; i < n; i++)
    {
        gcd = __gcd(gcd, arr[i]);
    }
    if (gcd == 1)
    {
        cout << 0 << "\n";
        return;
    }
    if (__gcd(gcd, n) == 1)
    {
        cout << 1 << "\n";
    }
    else if (__gcd(gcd, n - 1) == 1)
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 3 << "\n";
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
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
