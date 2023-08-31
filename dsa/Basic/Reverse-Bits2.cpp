#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

long reverseBits(long n)
{
    long rev = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        rev <<= 1;
        if ((n & 1) > 0)
        {
            rev ^= 1;
        }
        n >>= 1;
    }
    return rev;
}

int main()
{
    long n;
    cin >> n;

    cout << reverseBits(n) << endl;

    return 0;
}