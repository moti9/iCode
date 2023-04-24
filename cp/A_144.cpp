#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    long long n;
    cin >> n;
    string num = to_string(n);
    for (size_t i = 0; i < num.size(); i++)
    {
        if (num[i] - '0' >= 5)
        {
            if ((num[i] - '0') == 9 && i == 0)
            {
                continue;
            }
            num[i] = (9 - (num[i] - '0')) + '0';
        }
    }
    cout << num;
    return 0;
}