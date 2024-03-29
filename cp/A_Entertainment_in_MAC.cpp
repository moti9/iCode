#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(string &s)
{
    int left = 0, right = s.length() - 1;
    bool found = false;
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left += 1;
            right -= 1;
        }
        else if (s[left] > s[right])
        {
            found = true;
            break;
        }
        else
        {
            return false;
        }
    }
    return found;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n & 1)
        {
            if (check(s))
            {
                reverse(s.begin(), s.end());
                cout << s << "\n";
            }
            else
            {
                string temp = s;
                reverse(s.begin(), s.end());
                cout << temp + s << "\n";
            }
        }
        else
        {
            if (check(s))
            {
                string temp = s;
                reverse(s.begin(), s.end());
                cout << s + temp << "\n";
            }
            else
            {
                cout << s << "\n";
            }
        }
    }
    return 0;
}