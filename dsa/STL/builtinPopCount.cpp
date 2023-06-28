#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int count_setbits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}

int main()
{
    int n = 9;
    cout << count_setbits(n) << endl;
    cout << __builtin_popcount(n) << endl;
    cout << __builtin_popcountll(9999999999999999) << endl;

    return 0;
}