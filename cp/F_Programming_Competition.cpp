#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 5;

int parent[N], teamSize[N];

int findSet(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b)
{
    a = findSet(a);
    b = findSet(b);

    if (a != b)
    {
        if (teamSize[a] < teamSize[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        teamSize[a] += teamSize[b];
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // Initialize DSU
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            teamSize[i] = 1;
        }

        unordered_map<int, int> teamCount;

        // Process each employee
        for (int i = 2; i <= n; ++i)
        {
            int superior;
            cin >> superior;

            // Pair each employee with their direct superior
            unionSets(i, superior);
        }

        // Count the number of employees in each team
        for (int i = 1; i <= n; ++i)
        {
            teamCount[findSet(i)]++;
        }

        // Calculate the maximum number of teams
        int maxTeams = 0;
        for (const auto &entry : teamCount)
        {
            maxTeams += entry.second / 2;
        }

        cout << maxTeams << endl;
    }

    return 0;
}
