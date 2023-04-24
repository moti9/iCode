#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n, k;
    cin >> n >> k;
    int temp = n;
    for (int i = 0; i < k; i++)
    {
        if (temp % 10 != 0)
        {
            temp -= 1;
        }
        else
        {
            temp /= 10;
        }
    }
    cout << temp;

    return 0;
}