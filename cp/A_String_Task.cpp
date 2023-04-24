#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = tolower(s[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
        {
            continue;
        }
        else
        {
            cout << "." << ch;
        }
    }

    return 0;
}