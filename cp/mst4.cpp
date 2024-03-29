#include <bits/stdc++.h>

using namespace std;
map<int, int> m;

int main()
{
    int n, sum = 0, sum2 = 0, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    sum /= 2;
    while (sum2 <= sum && ans < n)
    {
        sum2 += v[ans];
        ans++;
    }

    cout << ans;
}

/*
Question 7: Loki’s Mind Stone
Problem Statement  :
*/