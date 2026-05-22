#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
    void backtrack(const string &s, const unordered_set<string> &wordSet, string &current, vector<string> &result)
    {
        if (s.empty())
        {
            result.push_back(current.substr(0, current.size() - 1));
            return;
        }

        for (size_t i = 1; i <= s.size(); i++)
        {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix))
            {
                current += prefix + " ";
                backtrack(s.substr(i), wordSet, current, result);
                current.erase(current.size() - prefix.size() - 1);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        string current;
        backtrack(s, wordSet, current, result);
        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordDict[i];
    }
    string s;
    cin >> s;

    Solution sol;
    vector<string> result = sol.wordBreak(s, wordDict);

    for (const string &str : result)
    {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}