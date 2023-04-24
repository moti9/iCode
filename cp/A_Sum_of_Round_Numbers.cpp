#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = to_string(n);
        int len = s.size();
        if (len == 1)
        {
            cout << len << "\n";
            cout << n << "\n";
            continue;
        }
        int i = 1;
        vector<int> v;
        while (n)
        {
            int temp = pow(10, i);
            int d = n % temp;
            if (d != 0)
            {
                v.push_back(d);
                n -= d;
            }
            i++;
        }
        cout << v.size() << "\n";
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}