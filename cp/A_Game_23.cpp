#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int logab(int a, int b)
{
    return log2(a) / log2(b);
}

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << 0;
        return 0;
    }
    if (m % n != 0)
    {
        cout << -1;
        return 0;
    }

    int temp = m / n;
    int move = 0;
    while (temp % 2 == 0)
    {
        move += 1;
        temp /= 2;
    }
    while (temp % 3 == 0)
    {
        move += 1;
        temp /= 3;
    }

    if (temp == 1)
    {
        cout << move;
    }
    else
    {
        cout << -1;
    }

    return 0;
}