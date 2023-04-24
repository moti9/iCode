#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    int mini = INT_MAX, maxi = INT_MIN;
    int minIndex = 0, maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= mini)
        {
            mini = x;
            minIndex = i;
        }
        if (x > maxi)
        {
            maxi = x;
            maxIndex = i;
        }
    }
    // cout << mini << " " << minIndex << endl;
    // cout << maxi << " " << maxIndex << endl;
    if (maxIndex < minIndex)
    {
        cout << maxIndex + (n - minIndex - 1);
    }
    else
    {
        cout << maxIndex + (n - minIndex - 2);
    }

    return 0;
}