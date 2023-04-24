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
        if (n <= 10)
        {
            cout << n << endl;
        }
        else
        {
            int ct = 0, temp = 20, add = 10, cp = 20;
            while (temp <= n)
            {
                ct++;
                temp += add;
                if (ct%9==0)
                {
                    temp = cp * 10;
                    add = add * 10;
                    cp = cp * 10;
                }
            }
            cout << 10 + ct << endl;
        }
    }

    return 0;
}