#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
void print(vector<int> ar[], string s)
{
    for (int i = 0; i < 26; i++)
    {
        cout << s[i] << endl;
        for (auto x : ar[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}
*/

void solvehere()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ar[26];
    string typed = "";
    // print(ar, s);
    // /*
    for (int i = 0; i < n - 1; i++)
    {
        char ch = s[i];
        int ind = ch - 'a';
        int tsz = typed.size();
        for (auto x : ar[ind])
        {
            if (x < tsz - 1)
            {
                string tp = typed.substr(x, 2);
                string ins = s.substr(i, 2);
                if (tp == ins)
                {
                    cout << "YES\n";
                    return;
                }
            }
            else
            {
                break;
            }
            // cout<<"Loop\n";
        }
        typed += s[i];
        ar[ind].push_back(tsz);
    }

    // print(ar, s);
    // */
    cout << "NO\n";
    return;
}
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
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
