#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> ans(n, -1);
        vector<pair<int, int>> graph[n];
        for (auto &x : redEdges)
        {
            graph[x[0]].push_back({x[1], 1});
        }
        for (auto &x : blueEdges)
        {
            graph[x[0]].push_back({x[1], 2});
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        for (int step = 0; !q.empty(); step++)
        {
            for (int i = q.size(); i > 0; i--)
            {
                auto x = q.front();
                q.pop();
                ans[x.first] = ans[x.first] == -1 ? step : ans[x.first];

                for (auto &y : graph[x.first])
                {
                    if (y.first == -1 || y.second == x.second)
                        continue;
                    q.push({y.first, y.second});
                    y.first = -1;
                }
            }
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
    vector<vector<int>> redEdge, blueEdge;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        redEdge.push_back({u, v});
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        blueEdge.push_back({u, v});
    }
    Solution sol;
    vector<int> ans = sol.shortestAlternatingPaths(n, redEdge, blueEdge);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}