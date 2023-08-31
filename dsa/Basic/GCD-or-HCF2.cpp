#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int calcGCD(int n, int m)
{
    int ans = 1;
    for (int i = 2; i <= min(n, m); i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            ans = i;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << calcGCD(n, m) << endl;

    return 0;
}