#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    // int neg = 0, pos = 0, ctn = 0, ctp = 0;
    // vector<pair<int, bool>> b;
    int counter = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
        {
            // int temp = a / 2;
            // b.push_back({a / 2, true});
            // if (temp > 0)
            // {
            //     pos += temp;
            // }
            // else
            // {
            //     neg += temp;
            // }
            cout << a / 2 << endl;
        }
        else
        {
            // int temp = floor((float)a / 2);
            // b.push_back({temp, false});
            // if (temp > 0)
            // {
            //     pos += temp;
            //     ctp += 1;
            // }
            // else
            // {
            //     neg += temp;
            //     ctn += 1;
            // }
            cout << ((a + counter) / 2) << "\n";
            counter *= (-1);
        }
    }
    // int sum = pos + neg;
    // if (sum != 0)
    // {
    //     for (auto &x : b)
    //     {
    //         if (x.second == false)
    //         {
    //             if (sum < 0)
    //             {
    //                 x.first += 1;
    //                 x.second = true;
    //                 sum += 1;
    //             }
    //         }
    //     }
    // }
    // for (auto x : b)
    // {
    //     cout << x.first << endl;
    // }
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
