#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int prime[128];
    prime[0] = prime[1] = 0;
    int p = 2;
    for (int i = 2; i < 128; i++)
        prime[i] = 1;
    while (p * p <= 127)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= 127; i += p)
                prime[i] = 0;
        }
        p++;
    }
    string s1, s2;
    for (auto i : s)
    {
        if (prime[i])
            s1 += i;
        else
            s2 += i;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    reverse(s2.begin(), s2.end());
    cout << s1 << s2;
}