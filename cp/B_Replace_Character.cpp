#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> freq, ci;
        for (int i = 0; i < n; i++)
        {
            freq[s[i]] += 1;
            ci[s[i]] = i;
        }
        int minf = n, maxf = 0;
        char minc, maxc;
        for (auto &x : freq)
        {
            if (x.second > maxf)
                maxf = x.second, maxc = x.first;
            if (x.second < minf)
                minf = x.second, minc = x.first;
        }
        s[ci[minc]] = maxc;
        s[ci[maxc]] = minc;
        cout << s << "\n";
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