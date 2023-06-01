#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << !arr[0] << endl;
        return;
    }
    vector<int> temp(arr.rbegin(), arr.rend());
    // reverse(temp.begin(), temp.end());
    if (temp == arr)
    {
        for (int i = 0; i < n; i++)
        {
            cout << !temp[i] << " ";
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << temp[i] << " ";
        }
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
