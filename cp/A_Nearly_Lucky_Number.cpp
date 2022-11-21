#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ll n;
    cin >> n;
    string s = to_string(n);
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '4' || s[i] == '7')
        {
            count += 1;
        }
    }
    if (count == 4 || count == 7)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}