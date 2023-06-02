#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int dfs(int curr, unordered_map<int, vector<int>> &graph, unordered_set<int> &vis)
    {
        vis.insert(curr);
        int cnt = 1;
        for (auto nb : graph[curr])
        {
            if (!vis.count(nb))
            {
                cnt += dfs(nb, graph, vis);
            }
        }
        return cnt;
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];

                if ((long long)ri * ri >= (long long)(xi - xj) * (xi - xj) + (long long)(yi - yj) * (yi - yj))
                {
                    graph[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> vis;
            int cnt = dfs(i, graph, vis);
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> bombs;
    for (int i = 0; i < n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        bombs.push_back({x, y, r});
    }

    Solution sol;
    cout << sol.maximumDetonation(bombs) << endl;

    return 0;
}