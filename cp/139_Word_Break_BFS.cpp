#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);

        visited[0] = true;

        while (!q.empty())
        {
            int start = q.front();
            if (start == n) {
                return true;
            }

            q.pop();

            for(int end = start + 1; end <= n; end++)
            {
                if (!visited[end] && wordSet.find(s.substr(start, end - start)) != wordSet.end()) {
                    visited[end] = true;
                    q.push(end);
                }
            }
        }
        
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