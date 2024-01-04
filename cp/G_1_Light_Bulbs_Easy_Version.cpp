#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> colors(2 * n);
    vector<int> lastSeen(n + 1, -1);

    for (int i = 0; i < 2 * n; ++i) {
        cin >> colors[i];
    }

    int minSize = 0;
    int numSets = 1;

    for (int i = 0; i < 2 * n; ++i) {
        if (lastSeen[colors[i]] != -1) {
            minSize++;
            numSets = (numSets * (i - lastSeen[colors[i]])) % MOD;
        } else {
            lastSeen[colors[i]] = i;
        }
    }

    cout << minSize << " " << numSets << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
