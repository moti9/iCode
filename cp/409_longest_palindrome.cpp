#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> ump;
        for (char ch : s)
        {
            ump[ch]++;
        }

        int len = 0;
        char oddChar = '\0';
        int maxCnt = 0;

        for (auto it = ump.begin(); it != ump.end(); it++)
        {
            if (it->second & 1)
            {
                if (maxCnt < it->second)
                {
                    maxCnt = it->second;
                    oddChar = it->first;
                }
            }
        }
        int maxLen = 0;
        for (auto it = ump.begin(); it != ump.end(); it++)
        {
            if (it->first != oddChar)
            {
                maxLen += (it->second - (it->second % 2));
            }
            else
            {
                maxLen += it->second;
            }
        }

        return maxLen;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    cout << Solution().longestPalindrome(s) << endl;

    return 0;
}