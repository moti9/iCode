#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    // vector<int> h(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> h[i];
    // }
    // int dol = h[0];
    // int en = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     en += (h[i] - h[i + 1]);
    //     if (en < 0)
    //     {
    //         dol -= en;
    //         en = 0;
    //     }
    // }

    int dol = 0, prev = 0;
    int en = 0;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        en += (prev - h);
        if (en < 0)
        {
            dol -= en;
            en = 0;
        }
        prev = h;
    }
    cout << dol << "\n";
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
