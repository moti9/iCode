#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    string s, s1 = "1111111", s0 = "0000000";
    cin >> s;
    int ct = 0, flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < i + 7; j++)
        {
            if (s[i] == s[j])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    if (flag == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}