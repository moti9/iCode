#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n;
        vector<int> memo(s.length(), -1);
        return dp(s.length() - 1, s, wordDict, memo);
    }

    bool dp(int i, string &s, vector<string> &wordDict, vector<int> &memo) {
        if (i < 0) return true;

        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        for (string word : wordDict) {
            int currSize = word.length();
            if (i - currSize + 1 < 0) {
                continue;
            }

            if (s.substr(i - currSize + 1, currSize) == word &&
                dp(i - currSize, s, wordDict, memo)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
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