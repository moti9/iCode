#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void print(int x, int n)
{
    cout << "Yes\n";
    cout << 1 << " " << x << "\n";
    cout << n - 1 << " ";
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
        {
            continue;
        }
        cout << i << " ";
    }
}

void solvehere()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "No";
    }
    else
    {
        /*
        int sum = n * (n + 1) / 2;
        for (int i = 2; i <= n; i++)
        {
            int gcd = __gcd(i, sum - i);
            if (gcd > 1)
            {
                print(i, n);
                return;
            }
        }
        cout << "No";
        */
        int s = n / 2;
        if (n % 2)
        {
            s = (n + 1) / 2;
        }
        cout << "Yes\n";
        cout << 1 << " " << s << "\n";
        cout << n - 1 << " ";
        for (int i = 1; i <= n; i++)
        {
            if (i == s)
            {
                continue;
            }
            cout << i << " ";
        }
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
