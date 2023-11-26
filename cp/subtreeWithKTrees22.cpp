#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool isPrime(int num)
    {
        if (num < 2)
        {
            return false;
        }
        if (num == 2)
        {
            return true;
        }
        if (num % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i * i <= num; i += 2)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int countPrimesSubtree(vector<vector<int>> &graph, vector<bool> &visited, int node)
    {
        visited[node] = true;
        int primeCount = isPrime(node) ? 1 : 0;

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                primeCount += countPrimesSubtree(graph, visited, neighbor);
            }
        }

        return primeCount;
    }

    bool hasKPrimeSubtree(int n, int k, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n + 1);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n + 1, false);
        visited[1] = true;

        for (auto it : graph[1])
        {
            int cnt = countPrimesSubtree(graph, visited, it);
            if (it == k)
                return true;
        }
        return false;
    }
};

int main()
{

    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution obj;
    bool res = obj.hasKPrimeSubtree(n, k, edges);

    cout << res << endl;
    return 0;
}