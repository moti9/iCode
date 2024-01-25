#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        vector<vector<int>> cd(4, vector<int>(2));
        for (int i = 0; i < 4; i++)
        {
            cin >> cd[i][0] >> cd[i][1];
        }
        sort(cd.begin(), cd.end());
        int l = abs(cd[0][1] - cd[1][1]);
        int b = abs(cd[2][1] - cd[3][1]);
        cout << (l * b) << endl;
    }
    return 0;
}