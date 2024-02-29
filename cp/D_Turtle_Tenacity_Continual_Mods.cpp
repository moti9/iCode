#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll findGCD(vector<ll> &arr, int n)
{
    ll result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = __gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
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

        ll gcd = findGCD(arr, n);
        if (gcd != 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}