#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> v;

bool prime[90000001];

void sieveAlgo()
{
    int size = 90000000;
    prime[0] = prime[1] = true;
    for (int i = 2; i * i <= size; i++)
    {
        if (!prime[i])
        {
            for (int j = i * i; j <= size; j += i)
                prime[j] = true;
        }
        // else
        //     v.push_back(i);
    }
    for (int i = 2; i <= size; i++)
    {
        if (!prime[i])
            v.push_back(i);
    }
}

 void solve()
 {
     int n;
     cin >> n;
//     sieveAlgo();
     cout << v[n - 1] << "\n";
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

    int ttt = 1;
    cin >> ttt;
    sieveAlgo();
    while (ttt--)
    {
         solve();
//        int n;
//        cin >> n;
//        cout << v[n - 1] << "\n";
    }
    return 0;
}
