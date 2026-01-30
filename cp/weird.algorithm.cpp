#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define endl "\n"
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    while (n > 0 && n != 1)
    {
        cout << n << " ";
        if (n & 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }
    }
    cout << n;

    return 0;
}