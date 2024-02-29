#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        set<int> distinct_k;
        for (int x = 0; pow(a, x) <= l; x++)
        {
            for (int y = 0; pow(a, x) * pow(b, y) <= l; y++)
            {
                int k = l / (pow(a, x) * pow(b, y));
                distinct_k.insert(k);
            }
        }
        cout << distinct_k.size() << endl;
    }
    return 0;
}