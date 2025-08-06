#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl "\n"

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cOrder(m);
    int ans = -1;
    unordered_map<int, int> mco;
    for (int i = 0; i < m; i++) {
        cin >> cOrder[i];
        mco[cOrder[i]] = i;
    }
    vector<int> cow(n, -1);
    unordered_map<int, int> kmp;
    for (int i = 0; i < k; i++) {
        int c, p;
        cin >> c >> p;
        if(c == 1) {
            ans = p;
        }
        cow[c - 1] = p;
        kmp[cow[i]] = i;
    }


    cout << ans << endl;
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}