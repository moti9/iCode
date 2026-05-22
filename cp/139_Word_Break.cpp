#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
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