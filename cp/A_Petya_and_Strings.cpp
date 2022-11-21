#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    string s1, s2;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        int s1v = s1[i], s2v = s2[i];
        if (s1v >= 65 && s1v <= 90)
        {
            s1[i] = s1v + 32;
        }
        if (s2v >= 65 && s2v <= 90)
        {
            s2[i] = s2v + 32;
        }
    }
    int flag = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        int s1v = s1[i], s2v = s2[i];
        if (s1v < s2v)
        {
            flag = -1;
            break;
        }
        else if (s2v < s1v)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "0\n";
    else if (flag == 1)
        cout << "1\n";
    else if (flag == -1)
        cout << "-1\n";

    return 0;
}