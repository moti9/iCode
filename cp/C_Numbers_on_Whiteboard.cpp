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
        int n;
        cin >> n;
        cout << 2 << "\n";
        int temp = ceil((float)(n + n - 1) / 2);
        cout << n - 1 << " " << n << "\n";
        for (int i = n - 2; i > 0; i--)
        {
            cout << i << " " << temp << "\n";
            temp = ceil((float)(temp + i) / 2);
        }
    }

    return 0;
}