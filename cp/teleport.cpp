#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int direct_distance = abs(a - b);
    int via_teleport_distance1 = abs(a - x) + abs(b - y);
    int via_teleport_distance2 = abs(a - y) + abs(b - x);
    int via_teleport_distance = min(via_teleport_distance1, via_teleport_distance2);

    cout << min(direct_distance, via_teleport_distance) << "\n";

    return 0;
}