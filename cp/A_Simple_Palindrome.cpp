#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printChar(int n, string st)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        string s = "aeiou";

        if (n < 5)
        {
            cout << s.substr(0, n % 5);
        }
        else
        {
            int cnt = 0;
            int rem = n % 5;
            int div = n / 5;
            for (char ch : s)
            {
                for (int i = 0; i < div; i++)
                {
                    cout << ch;
                }
                if (cnt < rem)
                {
                    cout << ch;
                    cnt++;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/