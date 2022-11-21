#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll buy = INT_MAX;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        buy = max(0LL, min(buy - 1, arr[i]));
        ans += buy;
    }
    cout << ans;
    return 0;
}