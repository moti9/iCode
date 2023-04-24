#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool isConcatenated(string &word, unordered_set<string> &st, unordered_map<string, bool> &mp)
    {
        if (mp[word])
        {
            return true;
        }
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);
            if (st.find(prefix) != st.end() && (st.find(suffix) != st.end() || isConcatenated(suffix, st, mp)))
            {
                return mp[word] = true;
            }
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        int n = words.size();
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;
        unordered_map<string, bool> mp;
        for (int i = 0; i < n; i++)
        {
            if (isConcatenated(words[i], st, mp))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    Solution sol;
    vector<string> ans = sol.findAllConcatenatedWordsInADict(words);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}