#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    string s;
    cin >> s;
    string sh;
    bool play = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> sh;
        if (s.find(sh[0])!=string::npos || s.find(sh[1])!=string::npos)
        {
            play = true;
        }
    }
    if (play)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}