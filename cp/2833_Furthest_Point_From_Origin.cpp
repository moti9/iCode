#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;
        for (char c : moves) {
            if (c == 'L') {
                left++;
            } else if (c == 'R') {
                right++;
            } else {
                blank++;
            }
        }
        return max(left, right) + blank - min(left, right);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string moves;
    cin >> moves;

    Solution sol;
    int result = sol.furthestDistanceFromOrigin(moves);
    cout << result << "\n";
    

    return 0;
}