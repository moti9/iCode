#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    double dfs(string &start, string &target, unordered_map<string, unordered_map<string, double>> &graph, unordered_map<string, int> &vis)
    {
        if (graph.count(start) == 0 || graph.count(target) == 0)
        {
            return -1.0;
        }
        if (start == target)
        {
            return 1.0;
        }
        vis[start] = 1;

        for (auto &neighbour : graph[start])
        {
            string next = neighbour.first;
            if (!vis[next])
            {
                double ans = dfs(next, target, graph, vis);
                if (ans != -1)
                {
                    return ans * neighbour.second;
                }
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = (double)(1.0 / values[i]);
        }
        vector<double> ans;
        for (auto q : queries)
        {
            string c = q[0];
            string d = q[1];
            unordered_map<string, int> visited;
            double val = dfs(c, d, graph, visited);
            ans.push_back(val);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> equations;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        equations.push_back({a, b});
    }
    vector<double> values;
    for (int i = 0; i < n; i++)
    {
        double val;
        cin >> val;
        values.push_back(val);
    }
    int m;
    cin >> m;
    vector<vector<string>> queries;
    for (int i = 0; i < m; i++)
    {
        string c, d;
        cin >> c >> d;
        queries.push_back({c, d});
    }

    Solution sol;
    vector<double> ans = sol.calcEquation(equations, values, queries);

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}