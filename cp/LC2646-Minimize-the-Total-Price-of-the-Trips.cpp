#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void solve(int st, int ed, vector<int> adj[], vector<bool> &vis, vector<int> &price, int sum, int &ans)
    {
        if (st == ed)
        {
            ans += (sum + price[ed]);
            return;
        }
        vis[st] = true;
        for (auto ad : adj[st])
        {
            if (!vis[ad])
            {
                solve(ad, ed, adj, vis, price, sum + price[st], ans);
            }
        }
        return;
    }

    void divPrice(int node, bool divpr, vector<int> adj[], vector<bool> &vis, vector<int> &price, int &sum)
    {
        if (!divpr)
        {
            price[node] /= 2;
            divpr = true;
        }
        else
        {
            divpr = false;
        }
        vis[node] = true;
        sum += price[node];
        for (auto ad : adj[node])
        {
            if (!vis[ad])
            {
                divPrice(ad, divpr, adj, vis, price, sum);
            }
        }
        return;
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        vector<int> adj[n];
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        int sum=0;
        divPrice(1, false, adj, vis, price, sum);
        for(auto p:price) cout<<p<<" ";
        cout<<sum<<endl;
        return sum;
        // Div Logic Start
        vector<int> fp = price;
        int sumfp = 0;
        for (auto p : price)
            sumfp += p;
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(n, false);
            vector<int> np = price;
            int sumnp = 0;
            divPrice(i, true, adj, vis, np, sumnp);
            if (sumnp <= sumfp)
            {
                sumfp = sumnp;
                fp = np;
            }
            vis.clear();
            np = price;
            sumnp = 0;
            divPrice(i, false, adj, vis, np, sumnp);
            if (sumnp <= sumfp)
            {
                sumfp = sumnp;
                fp = np;
            }
        }
        // cout << sumfp << endl;
        // for (auto f : fp)
        //     cout << f << " ";
        // cout << endl;
        // Div Logic END
        int ans = 0;
        for (auto tr : trips)
        {
            vector<bool> vis(n, false);
            int sum = 0;
            solve(tr[0], tr[1], adj, vis, fp, sum, ans);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector<vector<int>> trips(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> trips[i][0] >> trips[i][1];
    }
    Solution sol;
    cout << sol.minimumTotalPrice(n, edges, price, trips) << endl;

    return 0;
}