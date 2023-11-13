#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ? true : false;
    }

public:
    string sortVowels(string s)
    {
        unordered_map<char, int> mp;
        for (auto &ch : s)
        {
            if (isVowel(ch))
                mp[ch]++;
        }
        string temp = "AEIOUaeiou";
        int j = 0;
        for (auto &ch : s)
        {
            if (isVowel(ch))
            {
                while (mp[temp[j]] == 0)
                    j++;
                ch = temp[j];
                mp[temp[j]]--;
            }
        }
        return s;
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