#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int countDigits(int n)
{
    int digits = floor(log10(n) + 1);
    return digits;
}

int main()
{
    int n;
    cin >> n;

    cout << countDigits(n) << endl;

    return 0;
}