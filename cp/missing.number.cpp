#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define endl "\n"
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    for(ll i = 1; i <= n - 1; i++) {
        ll x;
        cin >> x;
        sum -= x;
    }
    cout << sum << endl;

    return 0;
}