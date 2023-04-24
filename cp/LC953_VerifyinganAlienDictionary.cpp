#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, char> mp;
        char ch = 'a';
        for (auto x : order)
        {
            mp[x] = ch;
            ch++;
        }
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                words[i][j] = mp[words[i][j]];
            }
        }
        for (auto s : words)
        {
            cout << s << endl;
        }
        return is_sorted(words.begin(), words.end());
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
    string order;
    cin >> order;

    Solution sol;
    cout << sol.isAlienSorted(words, order) << endl;

    return 0;
}