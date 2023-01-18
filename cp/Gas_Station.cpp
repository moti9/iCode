#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool solve(int ind, int fuel, bool next, int st, int n, vector<int> gas, vector<int> cost)
{
    if (fuel < 0)
        return false;
    if (ind == st && next)
    {
        return fuel >= 0;
    }
    if (fuel - cost[ind] < 0)
    {
        return false;
    }
    fuel -= cost[ind];
    ind = (ind + 1) % n;
    fuel += gas[ind];
    next = true;
    return solve(ind, fuel, next, st, n, gas, cost);
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    // for (int i = 0; i < n; i++)
    // {
    //     int fuel = gas[i] - cost[i];
    //     if (fuel < 0)
    //         continue;
    //     if (solve(i, gas[i], false, i, n, gas, cost))
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    int total = 0, fuel = 0, station = 0;
    for (int i = 0; i < n; i++)
    {
        fuel += (gas[i] - cost[i]);

        if (fuel < 0)
        {
            total += fuel;
            fuel = 0;
            station = i + 1;
        }
    }
    total += fuel;

    return total >= 0 ? station : -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}