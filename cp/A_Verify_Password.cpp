#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool is_sorted(const string &s)
{
    for (size_t i = 1; i < s.size(); ++i)
    {
        if (s[i] < s[i - 1])
        {
            return false;
        }
    }
    return true;
}

bool is_strong_password(const string &password)
{
    string letters, digits;
    for (char ch : password)
    {
        if (isdigit(ch))
        {
            digits += ch;
        }
        else if (isalpha(ch))
        {
            letters += ch;
        }
        else
        {
            return false;
        }
    }

    if (!is_sorted(digits) || !is_sorted(letters))
    {
        return false;
    }

    bool found_letter = false;
    for (char ch : password)
    {
        if (isalpha(ch))
        {
            found_letter = true;
        }
        else if (isdigit(ch) && found_letter)
        {
            return false;
        }
    }

    return true;
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
        string pass;
        cin >> pass;
        if (is_strong_password(pass))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}