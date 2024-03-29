#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solvehere()
{
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;

    v32 zero_inds(n), one_inds(n);

    zero_inds[0] = (s[0] == '0') ? 0 : -1;
    one_inds[n - 1] = (s[n - 1] == '1') ? n - 1 : n;

    forsn(i, 1, n)
    {
        zero_inds[i] = (s[i] == '0') ? i : zero_inds[i - 1];
        one_inds[n - i - 1] = (s[n - i - 1] == '1') ? n - i - 1 : one_inds[n - i];
    }

    set<p32> st;

    forn(i, m)
    {
        int left, right;
        cin >> left >> right;
        int zero_ind = one_inds[left - 1];
        int one_ind = zero_inds[right - 1];
        if (zero_ind > one_ind)
        {
            st.insert({-1, -1});
        }
        else
        {
            st.insert({zero_ind, one_ind});
        }
    }

    cout << st.size() << "\n";
}

int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it << ": ";
        solvehere();
    }
    return 0;
}