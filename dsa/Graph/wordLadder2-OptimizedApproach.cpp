#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string bw;
    int wlen;

    void dfs(string &word, vector<string> &seq)
    {
        if (word == bw)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for (int i = 0; i < wlen; i++)
        {
            char org_wordch = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (mp[word] > 0 && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }

            word[i] = org_wordch;
        }
        return;
    }

public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        bw = beginWord;
        wlen = beginWord.length();

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front();
            if (word == endWord)
                break;
            q.pop();
            int steps = mp[word];
            for (int i = 0; i < wlen; i++)
            {
                char org_wordch = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    {
                        q.push(word);
                        mp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = org_wordch;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
