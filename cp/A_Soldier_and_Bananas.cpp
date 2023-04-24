#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int req_pr = k * w * (w + 1) / 2;
    if (req_pr <= n)
    {
        cout << 0;
    }
    else
    {
        cout << req_pr - n;
    }

    return 0;
}