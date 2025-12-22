#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    
    int m;
    cin >> m;
    vector<string> wordDict(m);

    for (int i = 0; i < m; i++) {
        cin >> wordDict[i];
    }

    Solution sol;
    vector<string> result = sol.wordBreak(s, wordDict);
    for (const string& sentence : result) {
        cout << sentence << "\n";
    }

    return 0;
}