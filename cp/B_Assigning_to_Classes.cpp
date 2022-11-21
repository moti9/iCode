#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> arr(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        cout << abs(arr[n] - arr[n - 1]) << endl;
    }

    return 0;
}