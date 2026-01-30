#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> permutations;

    int start = 2;
    while (start <= n) {
        permutations.push_back(start);
        start += 2;
    }
    start = 1;
    while (start <= n) {
        permutations.push_back(start);
        start += 2;
    }

    bool valid = true;
    for (int i = 0; i < n - 1; i++) {
        if (abs(permutations[i] - permutations[i + 1]) == 1) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "NO SOLUTION" << endl;
        return 0;
    } 

    for (int i = 0; i < n; i++) {
        cout << permutations[i] << " ";
    }
    cout << endl;

    return 0;
}