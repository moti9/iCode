#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;

    // Upper half of the rhombus
    for (int i = 0; i <= n; ++i)
    {
        // Print leading spaces
        for (int j = 0; j < n - i; ++j)
        {
            cout << "  ";
        }

        // Print increasing digits
        for (int j = 0; j < i; ++j)
        {
            cout << j;
            if (j <= i)
            {
                cout << " ";
            }
        }

        // Print decreasing digits
        for (int j = i ; j >= 0; --j)
        {
            cout << j;
            if (j > 0)
            {
                cout << " ";
            }
        }

        cout << "\n";
    }

    // Lower half of the rhombus
    for (int i = n - 1; i >= 0; --i)
    {
        // Print leading spaces
        for (int j = 0; j < n - i; ++j)
        {
            cout << "  ";
        }

        // Print increasing digits
        for (int j = 0; j < i; ++j)
        {
            cout << j;
            if (j <= i)
            {
                cout << " ";
            }
        }

        // Print decreasing digits
        for (int j = i; j >= 0; --j)
        {
            cout << j;
            if (j > 0)
            {
                cout << " ";
            }
        }

        cout << "\n";
    }
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
