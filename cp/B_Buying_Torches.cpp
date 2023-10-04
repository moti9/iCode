#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        int x, y, k;
        cin >> x >> y >> k;

        long long sticks = 1, torches = 0;
        long long trades = 0;

        long long sticks_needed = k * y;

        // Calculate the number of trades needed to get enough sticks
        trades = (sticks_needed + x - 2) / (x - 1);

        cout << trades + k << endl;
    }
};

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
        solution moti;
    }
    return 0;
}
