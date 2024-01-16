#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        ll n;
        cin >> n;
        if (n <= 2)
        {
            cout << 1;
        }
        else if (n % 2 == 0)
        {
            cout << 2;
        }
        else
        {
            if (isPrime(n))
            {
                cout << 1;
            }
            else if (isPrime(n - 2))
            {
                cout << 2;
            }
            else
            {
                cout << 3;
            }
        }
    }
    return 0;
}