#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int bronze_before, silver_before, gold_before, platinum_before;
    int bronze_after, silver_after, gold_after, platinum_after;

    cin >> bronze_before >> bronze_after;
    cin >> silver_before >> silver_after;
    cin >> gold_before >> gold_after;
    cin >> platinum_before >> platinum_after;

    int platinum_promoted = platinum_after - platinum_before;
    int gold_promoted = (gold_after + platinum_promoted) - gold_before;
    int silver_promoted = (silver_after + gold_promoted) - silver_before;

    cout << silver_promoted << "\n";
    cout << gold_promoted << "\n";
    cout << platinum_promoted << "\n";

    return 0;
}