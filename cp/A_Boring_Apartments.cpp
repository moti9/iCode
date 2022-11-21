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

        string numStr = to_string(n);
        int prev = ((numStr[0] - '0') - 1) * 10;
        int curr = numStr[0] - '0';
        // int dig = 1;
        // int count = 0;
        // while (dig <= n)
        // {
        //     count += 1;
        //     dig = dig * 10 + (dig % 10);
        // }
        int count = numStr.size();
        int total = prev + count * (count + 1) / 2;
        cout << total << "\n";
        // cout << prev << endl;
        // cout << count << "\n";
    }

    return 0;
}