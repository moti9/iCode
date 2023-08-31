#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int findGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return findGCD(b, a % b);
}

int calcGCD(int n, int m)
{
    return findGCD(n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << calcGCD(n, m) << endl;

    return 0;
}