#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;

    int cube = n;
    int level = 1;
    int ct = 0;
    while (cube >= 0)
    {
        int reqCube = level * (level + 1) / 2;
        if (reqCube <= cube)
        {
            cube -= reqCube;
            level += 1;
            ct += 1;
        }
        else
        {
            break;
        }
    }
    cout << ct;

    return 0;
}