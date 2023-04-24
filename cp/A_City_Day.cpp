#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool checkW(vector<int> &arr, int idx, int left, int right, int n)
{
    // cout << "Hii";
    for (int i = left; i <= right; i++)
    {
        if (arr[idx] > arr[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int left = max(0, i - x);
        int right = min(n - 1, i + y);
        if (checkW(arr, i, left, right, n))
        {
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}