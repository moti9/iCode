#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int a, b;
    cin >> a >> b;
    int y = 1;
    while (a * 3 <= b * 2)
    {
        y++;
        a = a * 3;
        b = b * 2;
    }
    cout << y;

    return 0;
}