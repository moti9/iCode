#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int countDigits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += 1;
        n /= 10;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    cout << countDigits(n) << endl;

    return 0;
}