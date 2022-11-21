#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string s;
    cin >> s;
    bool div2 = false, div3 = false;
    int zero = 0;
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            zero += 1;
        }
        if (zero > 1 || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')
        {
            div2 = true;
        }
        sum += (s[i] - '0');
    }
    if (sum % 3 == 0)
    {
        div3 = true;
    }
    if (zero >= 1 && div2 && div3)
    {
        cout << "red\n";
    }
    else
    {
        cout << "cyan\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
