#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    if (len == 1)
    {
        cout << s;
        return 0;
    }
    int st = 0, mid = 0, end = len - 1;
    while (mid <= end)
    {
        if (s[mid] == '1')
        {
            swap(s[st], s[mid]);
            st += 2;
            mid += 2;
        }
        else if (s[mid] == '2')
        {
            mid += 2;
        }
        else
        {
            swap(s[end], s[mid]);
            end -= 2;
        }
    }
    cout << s;

    return 0;
}