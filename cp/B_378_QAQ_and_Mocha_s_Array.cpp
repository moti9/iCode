#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll gcdOfArr(vector<ll> &arr)
{
    ll ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        ans = __gcd(arr[i], ans);
    }
    return ans;
}

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
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll gcd = gcdOfArr(arr);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (gcd % arr[i] == 0)
                cnt++;
        }
        if (cnt > 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}