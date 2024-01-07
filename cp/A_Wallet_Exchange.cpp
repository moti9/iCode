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
        ll a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 0)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
        }
    }
    return 0;
}