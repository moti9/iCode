#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isPowerOfThree(int n)
{
    if (n <= 2)
    {
        if (n == 1)
        {
            return true;
        }
        return false;
    }

    while (n >= 3)
    {
        if (n % 3 != 0)
        {
            return false;
        }
        n /= 3;
    }
    if (n == 1)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfThree(n) << endl;

    return 0;
}