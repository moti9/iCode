#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    string s;
    cin >> s;
    int uc = 0, lc = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            uc++;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            lc++;
        }
    }
    if (uc > lc)
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s << "\n";
    }
    else
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << "\n";
    }

    return 0;
}