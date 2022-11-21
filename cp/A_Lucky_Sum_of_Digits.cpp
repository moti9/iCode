#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    int f = 0, s = 0;

    if (n % 7 == 0)
    {
        s = n / 7;
        while (s--)
        {
            cout << 7;
        }
        return 0;
    }

    for (int i = 1; i <= n / 4; i++)
    {
        int rem = n - (4 * i);
        if (rem % 7 == 0 && (rem / 7) > 0)
        {
            f = i;
            s = rem / 7;
            break;
        }
    }
    // cout << f << " " << s << endl;
    if (f > 0 && s > 0)
    {
        while (f--)
        {
            cout << 4;
        }
        while (s--)
        {
            cout << 7;
        }
    }
    else if (n % 4 == 0)
    {
        f = n / 4;
        while (f--)
        {
            cout << 4;
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}