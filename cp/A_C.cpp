#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        int step = 0;
        while (a <= n && b <= n)
        {
            if (a <= b)
            {
                a += b;
            }
            else
            {
                b += a;
            }
            step++;
        }
        cout << step << endl;
    }

    return 0;
}