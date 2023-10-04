#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        int n;
        cin >> n;
        string event;
        cin >> event;
        string room(10, '0');
        for (int i = 0; i < n; i++)
        {
            if (event[i] == 'L')
            {
                for (int i = 0; i <= 9; i++)
                {
                    if (room[i] == '0')
                    {
                        room[i] = '1';
                        break;
                    }
                }
            }
            else if (event[i] == 'R')
            {
                for (int i = 9; i >= 0; i--)
                {
                    if (room[i] == '0')
                    {
                        room[i] = '1';
                        break;
                    }
                }
            }
            else
            {
                room[event[i] - '0'] = '0';
            }
        }
        cout << room;
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
    // cin>>ttt;
    while (ttt--)
    {
        solution moti;
    }
    return 0;
}
