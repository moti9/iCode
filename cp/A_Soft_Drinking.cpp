#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drink = k * l;
    int slice = c * d;
    int salt = p;
    int rd = drink / nl;
    int rs = salt / np;

    int ans = min(slice, min(rd, rs));
    cout << ans / n;

    return 0;
}