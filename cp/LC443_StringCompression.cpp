#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0, j = 0, n = chars.size();
        while (i < n)
        {
            int len = 1;
            while (i + len < n && chars[i + len] == chars[i])
            {
                len++;
            }
            chars[j++] = chars[i];
            if (len > 1)
            {
                for (const char ch : to_string(len))
                {
                    chars[j++] = ch;
                }
            }
            i += len;
        }
        return j;
    }
};

int main()
{
    string s;
    cin >> s;

    vector<char> chars(s.begin(), s.end());
    Solution sol;

    int ans = sol.compress(chars);
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}