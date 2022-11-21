#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    int n;
    cin >> n;
    int ct = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[0] == 'X')
        {
            if (s[1] == '+')
                ct++;
            else if (s[1] == '-')
                ct--;
        }
        else
        {
            if (s[1] == '+')
                ++ct;
            else if (s[1] == '-')
                --ct;
        }
    }
    cout << ct << "\n";

    return 0;
}