#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int find(int x, vector<int> &pr)
{
    if (pr[x] == -1)
        return x;
    return pr[x] = find(pr[x], pr);
}

void unionStr(int i, int j, vector<int> &pr)
{
    i = find(i, pr);
    j = find(j, pr);

    if (i != j)
    {
        pr[max(i, j)] = min(i, j);
    }
}

string smallestEquivalentString(string s1, string s2, string baseStr)
{
    vector<int> pr(26, -1);
    for (int i = 0; i < s1.size(); i++)
    {
        unionStr(s1[i] - 'a', s2[i] - 'a', pr);
    }

    for (int i = 0; i < baseStr.size(); i++)
        baseStr[i] = find(baseStr[i] - 'a', pr) + 'a';

    return baseStr;
}

int main()
{
    string s1, s2, baseStr;
    cin >> s1;
    cin >> s2;
    cin >> baseStr;

    cout << smallestEquivalentString(s1, s2, baseStr) << endl;

    return 0;
}