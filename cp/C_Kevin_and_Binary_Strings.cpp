#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string xorStrings(string &a, string &b, int len)
{
    string xs = "";
    for (int i = 0; i < len; i++)
    {
        if (a[i] == b[i])
        {
            xs += '0';
        }
        else
        {
            xs += '1';
        }
    }
    return xs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                ind = i;
                break;
            }
        }

        cout << 1 << " ";
        cout << n << " ";
        if (ind == -1)
        {
            cout << 1 << " ";
            cout << 1 << "\n";
        }
        else
        {
            // need to find substr of s of size windSize whose xor with s will be maximum
            int winSize = n - ind;
            int startIndex = 0;
            string b = s.substr(ind, winSize);
            string maxXor = string(winSize, '0');
            for (int i = 0; i <= n - winSize; i++)
            {
                string curr = s.substr(i, winSize);
                string xs = xorStrings(b, curr, winSize);
                if (xs > maxXor)
                {
                    maxXor = xs;
                    startIndex = i;
                }
            }

            cout << startIndex + 1 << " ";
            cout << startIndex + winSize << "\n";
        }
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