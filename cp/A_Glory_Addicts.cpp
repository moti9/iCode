#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dam(vector<int> zero, int sz, vector<int> one, int so)
{
    int d = 0;
    bool flag = 1;
    int i = 0, j = 0;
    while (1)
    {
        if (flag && i < sz)
        {
            d += (2 * zero[i]);
            i++;
            flag = 0;
        }
        else if (flag = false && j < so)
        {
            d += (2 * one[j]);
            j++;
            flag = 1;
        }
        else
        {
            break;
        }
    }
    while (i < sz)
    {
        d += zero[i];
        i++;
    }
    while (j < so)
    {
        d += one[j];
        j++;
    }
    return d;
}

void solvehere()
{
    int n;
    cin >> n;
    vector<bool> s(n);
    for (int i = 0; i < n; i++)
    {
        bool skill;
        cin >> skill;
        s[i] = skill;
    }
    vector<int> zero, one;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (s[i])
        {
            one.push_back(x);
        }
        else
        {
            zero.push_back(x);
        }
    }
    if (n == 1)
    {
        if (s[0])
        {
            cout << one[0] << "\n";
            return;
        }
        else
        {
            cout << zero[0] << "\n";
            return;
        }
    }
    sort(zero.rbegin(), zero.rend());
    sort(one.rbegin(), one.rend());
    int damage = 0;
    int sz = zero.size();
    int so = one.size();
    bool flag = 1;
    if (zero[0] >= one[0])
    {
        damage += one[so - 1];
        one.resize(so - 1);
        so -= 1;
    }
    else
    {
        damage += zero[sz - 1];
        zero.resize(sz - 1);
        sz -= 1;
        flag = 0;
    }
    if (flag)
    {
        cout << dam(zero, sz, one, so) + damage << "\n";
        // cout<<"1\n";
    }
    else
    {
        cout << dam(one, sz, zero, so) + damage << "\n";
        // cout<<"2\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
