#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(vector<int> a, vector<int> b, int n, int k, int x)
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i] * x;
        if (b[i] < temp)
        {
            temp -= b[i];
            if (temp > k || k < 0)
            {
                return false;
            }
            k -= temp;
        }
    }
    return true;
}

void solvehere()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    int low = 0, high = 2002;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(a, b, n, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
