
//3
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main()
{
    

    return 0;
}
/*
// 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// 1.remain starts as n, divide by 2 each row, stop the loop when remain=1.
// 2.Integer step caches the distance the head might need to move, starts as 1, multiply by 2 each row.
// 3.direction starts as ->, turn around each row.
// 4.when direction is ->, the head move forward;
// when direction is <-, the head move forward if remain is odd, else does nothing.

int lastRemaining(int n)
{
    int head = 1, step = 1;
    bool flag = true;
    while (n > 1)
    {
        if (flag)
        {
            head += step;
        }
        else
        {
            head += n & 1 ? step : 0;
        }
        step *= 2;
        n /= 2;
        flag = !flag;
    }
    return head;
}

int main()
{
    int n;
    cin >> n;
    cout << lastRemaining(n) << endl;

    return 0;
}
*/

/*
// 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

char findTheDifference(string s, string t)
{
    int fr[26] = {0};
    int n = s.length();
    for (int i = 0; i < n + 1; i++)
    {
        if (i < n)
        {
            fr[s[i] - 'a']--;
        }
        fr[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (fr[i] > 0)
        {
            return char(i + 97);
        }
    }
    return ' ';
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << findTheDifference(s, t) << endl;

    return 0;
}
*/