#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool validate_sq(vector<vector<pair<int, int>>> &vp)
{
    int rs = vp[0][0].first;
    int cs = vp[0][0].second;

    int n = vp.size();
    int m = vp[0].size();

    if (n != m)
        return false;

    int re = vp[n - 1][0].first;
    int ce = vp[0][m - 1].second;

    int tcs = cs;

    for (auto &arr : vp)
    {
        for (auto &ar : arr)
        {
            if (ar.first == rs && ar.second == cs)
            {
                cs += 1;
            }
            else
            {
                return false;
            }
        }
        rs += 1;
        cs = tcs;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        vector<string> mat(n);
        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];
        }
        vector<vector<pair<int, int>>> temp;
        // unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            vector<pair<int, int>> vp;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == '1')
                {
                    // mp[i][j] = 1;
                    vp.push_back({i, j});
                }
            }
            if (vp.size() > 0)
            {
                temp.push_back(vp);
            }
        }

        if (temp.size() > 0 && temp[0].size() == temp.back().size())
        {
            if (validate_sq(temp))
                cout << "SQUARE\n";
            else
                cout << "TRIANGLE\n";
        }
        else
            cout << "TRIANGLE\n";
    }
    return 0;
}