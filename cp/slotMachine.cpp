#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int slotWheels(vector<string> history)
{
    int n = history.size();
    for (int i = 0; i < n; i++)
    {
        sort(history[i].begin(), history[i].end());
    }
    int m = history[0].length();
    int result = 0;
    for (int j = 0; j < m; j++)
    {
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, history[i][j] - '0');
        }
        result += maxi;
    }
    return result;
}

int main()
{

    return 0;
}