#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> b(n);
    vector<pair<ll, ll>> ai;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        ai.push_back({a, i});
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    sort(ai.begin(), ai.end());
    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[ai[i].second] = b[i];
    }
    for (auto an : ans)
    {
        cout << an << " ";
    }
    cout << "\n";
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

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007

// vector<ll> matchTemperatures(vector<ll> &a, vector<ll> &b, ll k)
// {
//     ll n = a.size();
//     vector<ll> indices(n);
//     vector<ll> sortedb = b;

//     for (ll i = 0; i < n; i++)
//     {
//         indices[i] = i + 1;
//     }

//     sort(sortedb.begin(), sortedb.end());
//     sort(indices.begin(), indices.end(), [&](ll i, ll j)
//          { return b[i - 1] < b[j - 1]; });

//     for (ll i = 0; i < n; i++)
//     {
//         ll j = indices[i] - 1;
//         if (abs(a[j] - sortedb[i]) > k)
//         {
//             return vector<ll>();
//         }

//         a[j] = sortedb[i];
//     }

//     return a;
// }

// /*

// ll findFirstLessEqual(vector<ll> &arr, ll x)
// {
//     ll start = 0;
//     ll end = arr.size() - 1;
//     ll result = -1;

//     while (start <= end)
//     {
//         ll mid = (start + end) / 2;

//         if (arr[mid] > x)
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             result = mid;
//             start = mid + 1;
//         }
//     }

//     return result;
// }

// ll findFirstGreaterEqual(vector<ll> &arr, ll x)
// {
//     ll start = 0;
//     ll end = arr.size() - 1;
//     ll result = -1;

//     while (start <= end)
//     {
//         ll mid = (start + end) / 2;

//         if (arr[mid] < x)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             result = mid;
//             end = mid - 1;
//         }
//     }

//     return result;
// }
// */

// void solvehere()
// {
//     ll n, k;
//     cin >> n >> k;
//     vector<ll> a(n), b(n);

//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (ll i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }
//     /*
//         sort(b.begin(), b.end());

//         vector<ll> ans;

//         for (int i = 0; i < n; i++)
//         {
//             ll temp1 = a[i] - k;
//             ll temp2 = a[i] + k;
//             ll i1 = findFirstGreaterEqual(b, temp1);
//             ll i2 = findFirstLessEqual(b, temp2);
//             if (i1 != -1 && i2 != -1)
//             {
//                 ll v1 = b[i1];
//                 ll v2 = b[i2];
//                 if (v1 < v2)
//                 {
//                     ans.push_back(v1);
//                     b.erase(b.begin() + i1);
//                 }
//                 else
//                 {
//                     ans.push_back(v2);
//                     b.erase(b.begin() + i2);
//                 }
//             }
//             else if (i1 != -1)
//             {
//                 ll v1 = b[i1];
//                 ans.push_back(v1);
//                 b.erase(b.begin() + i1);
//             }
//             else if (i2 != -1)
//             {
//                 ll v2 = b[0];
//                 ans.push_back(v2);
//                 b.erase(b.begin() + i2);
//             }
//         }

//         for (auto an : ans)
//         {
//             cout << an << " ";
//         }
//         cout << "\n";
//     */

//     vector<ll> ans = matchTemperatures(a, b, k);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << "\n";
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // #endif

//     ll ttt = 1;
//     cin >> ttt;
//     while (ttt--)
//     {
//         solvehere();
//     }
//     return 0;
// }
