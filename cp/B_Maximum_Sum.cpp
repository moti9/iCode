#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// ll solve(ll left, ll right, ll k, vector<ll> &arr)
// {
//     if (left > right)
//         return 0;
//     if (k == 0)
//         return 0;
//     ll lt = 0, rt = 0;
//     if (left + 1 < arr.size())
//         lt += arr[left] + arr[left + 1];
//     lt += solve(left + 2, right, k - 1, arr);
//     rt += arr[right] + solve(left, right - 1, k - 1, arr);
//     return min(lt, rt);
// }

void solvehere()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<ll> prefix(n + 1), suffix(n + 1);
    ll maxVal = 0;
    for (ll i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    reverse(arr.begin(), arr.end());
    for (ll i = 1; i <= n; i++)
    {
        suffix[i] = suffix[i - 1] + arr[i - 1];
    }
    for (ll i = 0; i <= k; i++)
    {
        ll left = prefix[2 * i];
        ll right = suffix[k - i];
        maxVal = max(maxVal, sum - (left + right));
    }
    cout << maxVal << endl;
    // sort(a.begin(), a.end());
    // ll i = 0, j = n - 1;
    // ll sum = accumulate(a.begin(), a.end(), 0LL);
    // cout << sum - solve(0, n - 1, k, a) << endl;
    // ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
