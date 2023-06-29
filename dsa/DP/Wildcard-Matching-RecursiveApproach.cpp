#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool checkMatching(int i, int j, string &pattern, string &str)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (j < 0 && i >= 0)
        {
            for (; i >= 0; i--)
            {
                if (pattern[i] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (pattern[i] == str[j] || pattern[i] == '?')
        {
            return checkMatching(i - 1, j - 1, pattern, str);
        }
        else if (pattern[i] == '*')
        {
            return checkMatching(i - 1, j, pattern, str) | checkMatching(i, j - 1, pattern, str);
        }
        return false;
    }

public:
    bool isMatch(string str, string pattern)
    {
        int n = pattern.length();
        int m = str.length();

        return checkMatching(n - 1, m - 1, pattern, str);
    }
};

int main()
{
    string str, pattern;
    cin >> str;
    cin >> pattern;

    Solution sol;
    cout << sol.isMatch(str, pattern) << endl;

    return 0;
}