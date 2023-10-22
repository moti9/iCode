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
        unordered_map<int, int> graph;
        for (int i = 1; i <= n; i++)
        {
            int fi;
            cin >> fi;
            graph[i] = fi;
        }
        for (int i = 1; i <= n; i++)
        {
            int a = graph[i];
            int b = graph[a];
            int c = graph[b];
            if (c == i)
            {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
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
