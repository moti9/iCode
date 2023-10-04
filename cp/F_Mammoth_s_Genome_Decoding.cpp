#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n % 4 != 0)
        {
            cout << "===\n";
        }
        else
        {
            int fr = n / 4;
            unordered_map<char, int> mp;
            for (auto &c : s)
            {
                mp[c]++;
            }
            if (mp['?'] == 0)
            {
                if (mp['A'] != fr || mp['C'] != fr || mp['G'] != fr || mp['T'] != fr)
                {
                    cout << "===\n";
                    return;
                }
                cout << s << "\n";
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == '?')
                    {
                        if (mp['?'] <= 0)
                        {
                            cout << "===\n";
                            return;
                        }
                        mp['?']--;
                        if (mp['A'] < fr)
                        {
                            s[i] = 'A';
                            mp['A']++;
                        }
                        else if (mp['C'] < fr)
                        {
                            s[i] = 'C';
                            mp['C']++;
                        }
                        else if (mp['G'] < fr)
                        {
                            s[i] = 'G';
                            mp['G']++;
                        }
                        else if (mp['T'] < fr)
                        {
                            s[i] = 'T';
                            mp['T']++;
                        }
                        else
                        {
                            cout << "===\n";
                            return;
                        }
                    }
                }
                if (mp['?'] != 0)
                {
                    cout << "===\n";
                    return;
                }
                else if (mp['A'] != fr || mp['C'] != fr || mp['G'] != fr || mp['T'] != fr)
                {
                    cout << "===\n";
                    return;
                }
                cout << s << "\n";
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        solution moti;
    }
    return 0;
}
