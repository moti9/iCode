#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    int idx = 0;
    int next = 1;
    while (idx < n)
    {
        t += s[idx];
        idx += next;
        next += 1;
    }
    cout << t;
    return 0;
}