#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        set<char> st;
        for (auto &ch : s)
            st.insert(ch);
        string uq = "";
        for (auto &c : st)
            uq += c;
        // cout << uq << "\n";
        unordered_map<char, char> ump;
        int m = uq.length();
        for (int i = 0; i < m / 2; i++)
        {
            ump[uq[i]] = uq[m - i - 1];
            ump[uq[m - i - 1]] = uq[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (ump.find(s[i]) != ump.end())
                s[i] = ump[s[i]];
        }
        cout << s << "\n";
    }

    return 0;
}