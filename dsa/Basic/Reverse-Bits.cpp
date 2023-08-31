#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

long reverseBits(long n)
{
    vector<int> bits(32, 0);
    int ind = 31;
    while (n > 0)
    {
        bits[ind] = n % 2;
        n /= 2;
        ind -= 1;
    }

    long num = 0;
    for (int i = 0; i < 32; i++)
    {
        if (bits[i] == 1)
        {
            num += (long)pow(2, i);
        }
    }
    return num;
}

int main()
{
    long n;
    cin >> n;

    cout << reverseBits(n) << endl;

    return 0;
}