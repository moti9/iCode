#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    int x;
    cin >> x;

    cout << (x + 4) / 5 << "\n";
    // Old Approach
    /*
    int step = 0, st = 0;
    while (x >= 5)
    {
        x -= 5;
        step++;
    }
    while (x >= 4)
    {
        x -= 4;
        step++;
    }
    while (x >= 3)
    {
        x -= 3;
        step++;
    }
    while (x >= 2)
    {
        x -= 2;
        step++;
    }
    while (x > 0)
    {
        x -= 1;
        step++;
    }

    cout << step << "\n";
    */
    return 0;
}