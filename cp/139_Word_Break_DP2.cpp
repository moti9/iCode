#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> memo(n, false);
        for(int i = 0; i < n; i++) {
            for(string word : wordDict) {
                int currSize = word.length();
                if (i - currSize + 1 < 0) {
                    continue;
                }

                if (s.substr(i - currSize + 1, currSize) == word &&
                    (i - currSize + 1 == 0 || memo[i - currSize])) {
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[n - 1];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }
    string s;
    cin >> s;

    Solution sol;
    bool result = sol.wordBreak(s, wordDict);
    cout << (result ? "true" : "false") << "\n";

    return 0;
}