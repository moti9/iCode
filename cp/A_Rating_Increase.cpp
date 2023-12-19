#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string ab;
    cin >> ab;

    int n = ab.length();

    for (int i = 1; i < n; i++)
    {
        string a = ab.substr(0, i);
        string b = ab.substr(i);

        if (a[0] != '0' && b[0] != '0' && stoi(b) > stoi(a))
        {
            cout << a << " " << b << "\n";
            return;
        }
    }
    cout << "-1\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
