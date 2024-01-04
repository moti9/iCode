#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

char get_lang(char &c)
{
    return (c == 'a' || c == 'e') ? 'V' : 'C';
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
        string ans = "";
        for (int i = n - 1; i >= 0;)
        {
            if (get_lang(s[i]) == 'C')
            {
                for (int j = 0; j < 3; j++)
                {
                    ans += s.back();
                    s.pop_back();
                }
                i -= 3;
            }
            else
            {
                ans += s.back();
                s.pop_back();
                ans += s.back();
                s.pop_back();
                i -= 2;
            }
            ans += '.';
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}