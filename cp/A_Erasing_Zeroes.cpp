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
        string s;
        cin >> s;
        bool ftone = false;
        int firstOne = -1, lastOne = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (ftone == false)
                {
                    firstOne = i;
                    ftone = true;
                }
                lastOne = i;
            }
        }
        // cout << firstOne << " " << lastOne << "\n";
        int count = 0;
        for (int i = firstOne + 1; i < lastOne; i++)
        {
            if (s[i] == '0')
            {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}