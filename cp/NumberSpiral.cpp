#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long y, x;
        cin >> y >> x;
        long long layer = max(x, y);
        long long layer_start = (layer - 1) * (layer - 1) + 1;
        long long result;
        if (layer % 2 == 0) {
            if (x == layer) {
                result = layer_start + (y - 1);
            } else {
                result = layer_start + (layer - 1) + (layer - x);
            }
        } else {
            if (y == layer) {
                result = layer_start + (x - 1);
            } else {
                result = layer_start + (layer - 1) + (layer - y);
            }
        }

        cout << result << "\n";
    }

    return 0;
}
