#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (size_t i = 1; i < n; i++)
    {
        cin >> arr[i];
    }
    int pos = 1;
    while (pos < t)
    {
        pos += arr[pos];
    }
    if (pos == t)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}