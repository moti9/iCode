#include <bits/stdc++.h>
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int vowelChk(char s)
{
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U' || s == 'Y')
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    fastio;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        char chr = tolower(str[i]);
        if (vowelChk(str[i]) == 1)
        {
            continue;
        }
        else
        {
            cout << "." << chr;
        }
    }

    return 0;
}