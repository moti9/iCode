#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<char> q;
        int radiant = 0, dire = 0;
        for (auto s : senate)
        {
            q.push(s);
            if (s == 'R')
            {
                radiant += 1;
            }
            else
            {
                dire += 1;
            }
        }
        int dban = 0, rban = 0;
        while (radiant && dire)
        {
            char s = q.front();
            q.pop();
            if (s == 'R')
            {
                if (rban)
                {
                    rban -= 1;
                    radiant -= 1;
                }
                else
                {
                    dban += 1;
                    q.push(s);
                }
            }
            else
            {
                if (dban)
                {
                    dban -= 1;
                    dire -= 1;
                }
                else
                {
                    rban += 1;
                    q.push(s);
                }
            }
        }
        return radiant ? "Radiant" : "Dire";
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.predictPartyVictory(s) << endl;

    return 0;
}