#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int max_count = 1;
    int current_count = 1;

    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            current_count++;
            if (current_count > max_count) {
                max_count = current_count;
            }
        } else {
            current_count = 1;
        }
    }

    cout << max_count << endl;

    return 0;
}