#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        int n, A, B;
        cin >> n >> A >> B;
        vector<int> sizes(n);
        int totalSize = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> sizes[i];
            totalSize += sizes[i];
        }
        double temp = (double)sizes[0] * (double)A;
        int water = (int)(temp / (float)totalSize);
        if (water >= B)
        {
            cout << "0\n";
            return;
        }
        int cnt = 0;
        sort(sizes.begin() + 1, sizes.end(), greater<int>());
        for (int i = 1; i < n; i++)
        {
            cnt += 1;
            totalSize -= sizes[i];
            water = (int)(temp / (float)totalSize);
            if (water >= B)
            {
                break;
            }
        }
        cout << cnt << "\n";
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
