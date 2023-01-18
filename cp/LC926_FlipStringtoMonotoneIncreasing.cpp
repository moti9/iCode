#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int func(int ind, string s)
    {
        if (ind < 0)
        {
            return 0;
        }
        int flip = INT_MAX, notflip = INT_MAX;
        flip = 1 + func(ind - 1, s);
        notflip = func(ind - 1, s);

        return min(flip, notflip);
    }

public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.length();
        int i = 0;
        int oneCt = 0, flip = 0;
        while (i < n && s[i] == '0')
        {
            i++;
        }
        for (; i < n; i++)
        {
            if (s[i] == '0')
            {
                flip++;
            }
            else
            {
                oneCt++;
            }
            if (flip > oneCt)
            {
                flip = oneCt;
            }
        }
        return flip;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minFlipsMonoIncr(s) << endl;

    return 0;
}