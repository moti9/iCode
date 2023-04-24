#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n, m;
    cin >> n >> m;
    bool last = true, start = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i % 2)
            {
                cout << "#";
            }
            else
            {
                if (last)
                {
                    if (j == m)
                    {
                        cout << "#";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
                else
                {
                    if (j == 1)
                    {
                        cout << "#";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
            }
        }
        if (i % 2 == 0)
            last = !last;
        cout << "\n";
    }

    return 0;
}