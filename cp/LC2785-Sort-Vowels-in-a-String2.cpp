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
        string temp = "";
        for (auto &ch : s)
        {
            if (isVowel(ch))
                temp += ch;
        }
        sort(temp.begin(), temp.end());
        int j = 0;
        for (auto &ch : s)
        {
            if (isVowel(ch))
            {
                ch = temp[j++];
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