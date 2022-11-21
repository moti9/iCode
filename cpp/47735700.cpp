#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cpp_int f = 1;
        cin >> n;
        for (int i = n; i >= 1; i--)
        {
            f *= i;
        }
        cout << f << endl;
    }

    return 0;
}