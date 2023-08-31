#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool isVowel(char &ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    char getChar(map<char, int> &mp)
    {
        for (auto &x : mp)
        {
            if (x.second > 0)
            {
                x.second -= 1;
                return x.first;
            }
        }
        return 'M';
    }

public:
    string sortVowels(string s)
    {
        map<char, int> mp;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]) == true)
            {
                mp[s[i]]++;
            }
        }
        string t = s;
        for (int i = 0; i < n; i++)
        {
            if (isVowel(t[i]) == true)
            {
                t[i] = getChar(mp);
            }
        }
        return t;
    }
};
int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.sortVowels(s) << endl;

    return 0;
}