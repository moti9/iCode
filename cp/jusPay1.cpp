#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solution_function()
{
    int n;
    cin >> n;

    int ans = 1e9 + 1;
    int maxWeight = -1;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
    {
        int edge;
        cin >> edge;
        int start = i;
        int end = edge;
        if (end != -1)
        {
            weight[end] += start;
            if (ans <= weight[end])
            {
                ans = max(ans, weight[end]);
                maxWeight = end;
            }
        }
    }
    if (ans != 1e9 + 1)
    {
        cout << maxWeight << "\n";
        return;
    }
    cout << -1 << "\n";
}

int main()
{
    int test;
    cin >> test;

    for (int tt = 1; tt <= test; tt += 1)
    {
        solution_function();
    }

    return 0;
}