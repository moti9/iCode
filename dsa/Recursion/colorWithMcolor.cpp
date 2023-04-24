#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isSafe(int node, int n, vector<vector<int>> graph, vector<int> color, int col)
{

    for (int i = 0; i < n; i++)
    {
        if (i != node && graph[i][node] == 1 && color[i] == col)
        {
            return false;
        }
    }
    return true;
}

bool graphColoring(int node, int n, int m, vector<vector<int>> graph, vector<int> &color)
{
    if (node == n)
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, n, graph, color, i))
        {
            color[node] = i;
            if (graphColoring(node + 1, n, m, graph, color))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

int main()
{
    int n = 4;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[2][1] = 1;
    graph[1][2] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;
    graph[0][3] = 1;
    graph[3][0] = 1;
    graph[3][1] = 1;
    graph[1][3] = 1;

    int m;
    cin >> m;

    vector<int> color(n, 0);

    if (graphColoring(0, n, m, graph, color))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}