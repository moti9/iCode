#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            cout << "YES\n";
            cout << s.substr(i, 2);
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}