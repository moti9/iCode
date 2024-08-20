#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        cout << (((n >= 102 && n <= 109) || (n >= 1010 && n <= 1099)) ? "YES\n" : "NO\n");
    }
    return 0;
}