#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(string word, string &bword, int &wlen, unordered_map<string, int> &mp, vector<string> &seq, vector<vector<string>> &ans)
    {
        if (word == bword)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mp[word];
        for (int i = 0; i < wlen; i++)
        {
            char org_ch = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (mp[word] != 0 && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, bword, wlen, mp, seq, ans);
                    seq.pop_back();
                }
            }
            word[i] = org_ch;
        }
        return;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        queue<string> qs;
        qs.push(beginWord);
        unordered_map<string, int> mpp;
        mpp[beginWord] = 1;

        int wlen = beginWord.length();

        while (!qs.empty())
        {
            string word = qs.front();
            qs.pop();
            if (word == endWord)
            {
                break;
            }
            int steps = mpp[word];

            for (int i = 0; i < wlen; i++)
            {
                char org_ch = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word))
                    {
                        st.erase(word);
                        mpp[word] = steps + 1;
                        qs.push(word);
                    }
                }
                word[i] = org_ch;
            }
        }
        vector<vector<string>> ans;
        if (mpp[endWord])
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, beginWord, wlen, mpp, seq, ans);
        }
        return ans;
    }
};

int main()
{
    string beginWord;
    cin >> beginWord;
    string endWord;
    cin >> endWord;
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordList[i];
    }

    Solution sol;
    vector<vector<string>> ans = sol.findLadders(beginWord, endWord, wordList);

    for (auto list_str : ans)
    {
        for (auto str : list_str)
            cout << str << " ";
        cout << "\n";
    }

    return 0;
}