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
    string s;
    s.resize(n);
    cin >> s;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            ct++;
        }
    }
    cout << ct << "\n";
    return 0;
}