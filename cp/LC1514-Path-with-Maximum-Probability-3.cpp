#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Bellman-Ford Algorithm

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        int m = succProb.size();
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        for (int i = 1; i < n; i++)
        {
            bool noUpdate = true;
            for (int j = 0; j < m; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if (maxProb[u] * prob > maxProb[v])
                {
                    maxProb[v] = maxProb[u] * prob;
                    noUpdate = false;
                }

                if (maxProb[v] * prob > maxProb[u])
                {
                    maxProb[u] = maxProb[v] * prob;
                    noUpdate = false;
                }
            }

            if (noUpdate == true)
            {
                break;
            }
        }

        return maxProb[end];
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<double> succProb(m);
    for (int i = 0; i < m; i++)
    {
        cin >> succProb[i];
    }

    int start, end;
    cin >> start >> end;

    Solution sol;
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}