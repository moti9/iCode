#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int calcGCD(int n, int m)
{
    return __gcd(n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << calcGCD(n, m) << endl;

    return 0;
}