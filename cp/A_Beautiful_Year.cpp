#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
int checkyr(int n)
{
    int digit, flag = 1;
    vector<int> v;
    while (n != 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == v[i + 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main()
{
    fastio();
    int n;
    cin >> n;
    for (int i = n + 1; i <= 10000; i++)
    {
        if (checkyr(i) == 1)
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}