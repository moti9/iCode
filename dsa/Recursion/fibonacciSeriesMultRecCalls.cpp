#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int fibSeries(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int last = fibSeries(n - 1);
    int start = fibSeries(n - 2);

    return last + start;
}

int main()
{
    int n;
    cin >> n;
    cout << fibSeries(n) << endl;

    return 0;
}