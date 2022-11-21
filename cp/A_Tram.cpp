#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    int cap = 0;
    int curr = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (i == 1 || i == n)
        {
            if (i == 1)
            {
                curr = curr + b;
                cap = max(cap, curr);
            }
            else
            {
                curr = curr - a;
                cap = max(cap, curr);
            }
        }
        else
        {
            curr = curr - a + b;
            cap = max(curr, cap);
        }
    }
    cout << cap;

    return 0;
}