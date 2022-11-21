#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    string s;
    cin >> s;
    if (s[0] >= 97)
    {
        s[0] -= 32;
    }
    cout << s;

    return 0;
}