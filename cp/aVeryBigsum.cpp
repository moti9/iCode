#include <bits/stdc++.h>
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
long int aVeryBigSum(int a[], int n)
{
    long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    cout << sum;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    aVeryBigSum(a, n);

    return 0;
}